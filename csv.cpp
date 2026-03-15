#include "csv.h"

bool CSV::lire()
{
  std::ifstream file(nom_fichier);
  if (!file.is_open())
  {
    std::cerr << "Erreur ouverture lecture: " << nom_fichier << "\n";
    return false;
  }

  data.clear();
  std::string line;
  while (getline(file, line))
  {
    std::istringstream ss(line);
    std::string cell;
    int annee = 0, position = 0;
    std::list<std::string> liste;

    while (getline(ss, cell, ';'))
    {
      if (position == 0)
        annee = std::stoi(cell);
      else if (!cell.empty())
        liste.push_back(cell);
      position++;
    }
    data[annee] = liste;
  }
  return true;
}

bool CSV::ecrire() const
{
  std::ofstream file(nom_fichier);
  if (!file.is_open())
  {
    std::cerr << "Erreur ouverture écriture: " << nom_fichier << "\n";
    return false;
  }

  for (const auto &[annee, liste] : data)
  {
    file << annee;
    for (const auto &ev : liste)
      file << ";" << ev;
    file << "\n";
  }
  return true;
}

void CSV::ajouter_evenement(const int &annee, const std::string &evenement)
{
  data[annee].push_back(evenement);
}

void CSV::afficher() const
{
  for (const std::pair<const int, std::list<std::string>> &pair : data)
  {
    std::cout << "Année " << pair.first << " :"; // << std::endl;
    if (pair.second.size() <= 1)
    {
      std::cout << " " << pair.second.front() << std::endl;
    }
    else
    {
      std::cout << std::endl;
      for (const std::string &evenement : pair.second)
      {
        std::cout << " - " << evenement << std::endl;
      }
    }
  }
}