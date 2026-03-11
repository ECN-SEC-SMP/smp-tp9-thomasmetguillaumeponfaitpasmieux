#pragma once

#include <map>
#include <list>
#include <string>

class CSV
{
public:
  std::map<int, std::list<std::string>> lire_csv(const std::string &nom_fichier);
  void ecrire_csv(const std::string &nom_fichier, const std::map<int, std::list<std::string>> &mapIntListString);
};