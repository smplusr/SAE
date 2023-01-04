/**
 * \file fonctions.cpp
 * 
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <algorithm>

/**
 * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
 * 
 * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
 * 
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabAleat(size_t N)
{
  std::vector<int> tab(N);
  for (auto& val : tab)
    val = rand();
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 * 
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  for (int i = 0; i < N-1; i++)
  {
    if (rand() % 2 == 0)
    {
      std::swap(tab[i], tab[i + 1]);
      ++i;
    }
  }
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[0], tab[1]);
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[N - 1], tab[N - 2]);
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[N - 1], tab[0]);
  return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 * 
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName)
{
  const size_t taille = tab.size();
  for (size_t i = 1; i < taille; i++)
  {
    if (tab[i - 1] > tab[i])
    {
      std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
      exit(EXIT_FAILURE);
    }
  }
}


size_t triSelection(std::vector<int>& tab) {
    size_t nb_comp = 0;
    size_t n = tab.size();
    int min;
    for (size_t i = 0; i < n - 1; ++i/*, nb_comp++*/) {
        //nb_comp++;
        min = i;
        for (size_t j = i + 1; j < n; ++j/*, nb_comp++*/) {
            //nb_comp++;
            nb_comp++;
            if (tab[j] < tab[min]) {
                min = j;
            }
        }
        nb_comp++;
        if (min != i) {
            int temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
        }
    }
    return nb_comp;
}

size_t triBulles (std::vector<int> &tab) {
    size_t nb_comp = 0;
    for (size_t i = (tab.size () - 1); i >= 1; i--)
        for (size_t j = 0; j <= i - 1; j++, nb_comp++)
            if (tab[j] > tab[j + 1])
                std::swap (tab[j], tab[j + 1]);
    return nb_comp;
}




size_t triBullesOpti (std::vector<int> &tab) {
    size_t nb_comp = 0;
    for (size_t i = (tab.size () - 1); i >= 1; i--) {
        bool sorted = true;
        for (size_t j = 0; j <= i - 1; j++, nb_comp++)
            if (tab[j] > tab[j + 1]) {
                std::swap (tab[j], tab[j + 1]);
                sorted = false;
            }
        if (sorted)
            break;
    }
    return nb_comp;
}





size_t triPeigne(std::vector<int>& tab)
{
    size_t nb_comp = 0;
    bool change = false;
    int space = tab.size();
    while (space > 1 || change) {
        space = int(space / 1.3);
        if (space < 1) {
            space = 1;
        }
        int i = 0;
        change = false;
        while (i < tab.size() - space) {
            nb_comp++;
            if (tab[i] > tab[i + space]) {
                std::swap (tab[i],tab[i + space]);
                change = true;
            }
            i++;
        }
        
    }    
    return nb_comp;
}



size_t rapide_nb_comp = 0;

size_t partition (std::vector<int> &tab, int lo, int hi) {
    size_t pivot = tab[hi],
        i = lo - 1;

    for (size_t j = lo; j <= hi; j++, rapide_nb_comp++) {
            if (tab[j] <= pivot)
                std::swap (tab[++i], tab[j]);
    }

    return i;
}

size_t triRapide (std::vector<int> &tab, int lo, int hi) {
    if (lo >= hi || lo < 0)
        return rapide_nb_comp;

    size_t p = partition (tab, lo, hi);

    triRapide (tab, lo, p - 1);
    triRapide (tab, p + 1, hi);
    return rapide_nb_comp;
}

size_t triRapideHandler (std::vector<int> &tab) {
	return triRapide (tab, 0, tab.size () - 1);
}




bool sorted (std::vector<int> &tab) {
    const size_t size = tab.size();
    
    for (size_t i = 1; i < size; i++)
        if (tab[i - 1] > tab[i])
        return false;
        
    return true;
}

size_t triDebile (std::vector<int> &tab) {
    srand(unsigned(time(NULL)));
    size_t nb_comp = 0;

    for (; !sorted (tab); nb_comp++)
        std::random_shuffle(tab.begin(), tab.end());

    return nb_comp;
}



size_t triInsertion (std::vector<int> &tab) {
    size_t nb_comp = 0;
    for (size_t i = 1; i < tab.size(); i++, nb_comp++)
    {
        int var = tab[i], j = i;
        for (; j > 0 && tab[j - 1] > var; j--, nb_comp++)
            tab[j] = tab[j - 1];

        tab[j] = var;
    }
    return nb_comp;
}
