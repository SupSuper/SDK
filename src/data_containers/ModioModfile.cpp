#include "data_containers/ModioModfile.h"

extern "C"
{
  void modioInitModfile(ModioModfile* modfile, json modfile_json)
  {
    modfile->id = -1;
    if(modio::hasKey(modfile_json, "id"))
      modfile->id = modfile_json["id"];

    modfile->mod_id = -1;
    if(modio::hasKey(modfile_json, "mod_id"))
      modfile->mod_id = modfile_json["mod_id"];

    modfile->virus_status = -1;
    if(modio::hasKey(modfile_json, "virus_status"))
      modfile->virus_status = modfile_json["virus_status"];

    modfile->virus_positive = -1;
    if(modio::hasKey(modfile_json, "virus_positive"))
      modfile->virus_positive = modfile_json["virus_positive"];

    modfile->date_added = -1;
    if(modio::hasKey(modfile_json, "date_added"))
      modfile->date_added = modfile_json["date_added"];

    modfile->date_scanned = -1;
    if(modio::hasKey(modfile_json, "date_scanned"))
      modfile->date_scanned = modfile_json["date_scanned"];

    modfile->filesize = -1;
    if(modio::hasKey(modfile_json, "filesize"))
      modfile->filesize = modfile_json["filesize"];

    modfile->filename = NULL;
    if(modio::hasKey(modfile_json, "filename"))
    {
      std::string filename_str = modfile_json["filename"];
      modfile->filename = new char[filename_str.size() + 1];
      strcpy(modfile->filename, filename_str.c_str());
    }

    modfile->version = NULL;
    if(modio::hasKey(modfile_json, "version"))
    {
      std::string version_str = modfile_json["version"];
      modfile->version = new char[version_str.size() + 1];
      strcpy(modfile->version, version_str.c_str());
    }

    modfile->virustotal = NULL;
    if(modio::hasKey(modfile_json, "virustotal"))
    {
      std::string virustotal_str = modfile_json["virustotal"];
      modfile->virustotal = new char[virustotal_str.size() + 1];
      strcpy(modfile->virustotal, virustotal_str.c_str());
    }

    modfile->changelog = NULL;
    if(modio::hasKey(modfile_json, "changelog"))
    {
      std::string changelog_str = modfile_json["changelog"];
      modfile->changelog = new char[changelog_str.size() + 1];
      strcpy(modfile->changelog, changelog_str.c_str());
    }

    modfile->download = NULL;
    if(modio::hasKey(modfile_json, "download"))
    {
      std::string download_str = modfile_json["download"];
      modfile->download = new char[download_str.size() + 1];
      strcpy(modfile->download, download_str.c_str());
    }
    
    if(modio::hasKey(modfile_json, "filehash"))
    {
      modioInitFilehash(&(modfile->filehash), modfile_json["filehash"]);
    }
  }

  void modioFreeModfile(ModioModfile* modfile)
  {
    delete modfile;
  }
}