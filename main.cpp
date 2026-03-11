#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>

void ajouter_evenement(std::map<int, std::list<std::string>> &mapIntListString, const int &annee, const std::string &evenement)
{
  mapIntListString[annee].push_back(evenement);
}

void afficher_map(const std::map<int, std::list<std::string>> &mapIntListString)
{
  for (const std::pair<const int, std::list<std::string>> &pair : mapIntListString)
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

int main(int argc, char *argv[])
{
  // PARTIE 1 : VECTEUR D’ENTIERS
  std::cout << "PARTIE 1 : VECTEUR D’ENTIERS" << std::endl;
  std::vector<int> vInt; // vecteur d'entiers
  vInt.resize(3);        // redimensionnement du vecteur à 3 éléments
  vInt[0] = 1;           // affectation de la valeur 1 à l'élément d'indice 0
  vInt[1] = 2;           // affectation de la valeur 2 à l'élément d'indice 1
  vInt[2] = 3;           // affectation de la valeur 3 à l'élément d'indice 2

  std::cout << "Contenu du vecteur vInt :" << std::endl;
  // affichage du contenu du vecteur vInt
  std::cout << "W/ indices :" << std::endl;
  for (size_t i = 0; i < vInt.size(); i++)
  {
    std::cout << "vInt[" << i << "] = " << vInt[i] << std::endl;
  }
  std::cout << "W/ boucle sur une plage :" << std::endl;
  int index = 0;
  for (int &i : vInt)
  {
    std::cout << "vInt[" << index << "] = " << i << std::endl;
    index++;
  }
  std::cout << "W/ iterateurs :" << std::endl;
  for (std::vector<int>::iterator itvec = vInt.begin(); itvec != vInt.end(); ++itvec)
  {
    std::cout << "vInt[" << std::distance(vInt.begin(), itvec) << "] = " << *itvec << std::endl;
  }

  // PARTIE 2 : VECTEUR DE CHAINES DE CARACTÈRES
  std::cout << "PARTIE 2 : VECTEUR DE CHAINES DE CARACTÈRES" << std::endl;
  std::vector<std::string> phrase;
  phrase.push_back("Bonjour");
  phrase.push_back("comment");
  phrase.push_back("allez");
  phrase.push_back("vous");
  phrase.push_back("?");

  // pour afficher la taille du vector
  std::cout << phrase.size() << std::endl;

  // pour afficher la capacité du vector
  std::cout << phrase.capacity() << std::endl;

  // pour afficher la phrase
  for (std::string &mot : phrase)
  {
    std::cout << mot << " ";
  }
  std::cout << std::endl;

  // echange de valeur
  auto it1 = phrase.begin() + 1;
  auto it3 = phrase.begin() + 3;
  it1->swap(*it3);

  for (std::string &mot : phrase)
  {
    std::cout << mot << " ";
  }
  std::cout << std::endl;

  // insérer un élément dans le vecteur
  auto pos = c1.begin();
  pos = phrase.insert(pos+1, "a");
  pos = phrase.insert(pos+2, "tous");
  phrase.insert();
  // PARTIE 3 : LES LISTES
  std::cout << "PARTIE 3 : LES LISTES" << std::endl;
  std::list<int> listInt{89, 2, 56, 2, 6, 5, 6, 8}; // liste d'entiers de taille 8
  for (std::list<int>::iterator itlist = listInt.begin(); itlist != listInt.end(); ++itlist)
  {
    std::cout << *itlist << " ";
  }
  std::cout << std::endl;
  listInt.erase(std::next(listInt.begin(), 2)); // suppression de l'élément 3
  for (std::list<int>::iterator itlist = listInt.begin(); itlist != listInt.end(); ++itlist)
  {
    std::cout << *itlist << " ";
  }
  std::cout << std::endl;

  // PARTIE 4 : LES MAPS
  std::cout << "PARTIE 4 : LES MAPS" << std::endl;
  std::map<int, std::list<std::string>> mapIntListString; // map d'entiers vers des listes de chaînes de caractères
  ajouter_evenement(mapIntListString, 1789, "Prise de la Bastille");
  ajouter_evenement(mapIntListString, 1989, "Chute du mur de Berlin");
  ajouter_evenement(mapIntListString, 1998, "Victoire de la France en Coupe du Monde de football");
  ajouter_evenement(mapIntListString, 2001, "Attentats du 11 septembre");
  ajouter_evenement(mapIntListString, 2001, "Lancement de Wikipédia");
  afficher_map(mapIntListString);

  // PARTIE 5 : LECTURE/ÉCRITURE DE FICHIER CSV
  std::cout << "PARTIE 5 : LECTURE/ÉCRITURE DE FICHIER CSV" << std::endl;
  return 0;
}