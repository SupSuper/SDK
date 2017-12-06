#include "instance/ModIOInstance.h"

int main(void)
{
  modio::Instance modio_instance(7, "e91c01b8882f4affeddd56c96111977b");

  volatile static bool finished = false;

  auto wait = [&]()
  {
    while (!finished)
    {
      modio::sleep(10);
      modioProcess();
    }
  };

  auto finish = [&]()
  {
    finished = true;
  };

  // Sometimes, mod.io API will return errors. Let's trigger some of them to find out how to interpret them
  modio::FilterHandler filter;
  filter.setLimit(-1);
  filter.addFieldValue("id", "-1");

  std::cout <<"Getting mods..." << std::endl;

  modio_instance.getMods(filter, [&](const modio::Response& response, const std::vector<modio::Mod> & mods)
  {
    std::cout << "On mod get response: " << response.code << std::endl;

    if(response.code == 200)
    {
      std::cout << "Success!" << std::endl;
    }else
    {
      // A general error message is returned
      std::cout << "Error message: " << response.error.message << std::endl;
      if(response.error.errors.size() > 0)
      {
        std::cout << "Errors:" << std::endl;
        // and we can go into details on the error list
        for(auto& error : response.error.errors)
        {
          std::cout << error << std::endl;
        }
      }
    }

    finish();
  });

  wait();

  modioShutdown();

  std::cout << "Process finished" << std::endl;

  return 0;
}
