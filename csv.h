#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class CSV
{
private:
  std::string nom_fichier;
  std::map<int, std::list<std::string>> data;

public:
  CSV(const std::string &nom_fichier) : nom_fichier(nom_fichier) {}
  bool lire();
  bool ecrire() const;
  void ajouter_evenement(const int &annee, const std::string &evenement);
  void afficher() const;
};