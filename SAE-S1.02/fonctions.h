/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

#include <fstream>  // required by writeCSV


//!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Vérifie qu'un tableau est correctement trié
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});






//Nos fonctions

/*
    Implement a selective sorting.
    Should return an integer containing the number of comparisions.
*/
size_t triSelection(std::vector<int>& tab);




/*
    Implements a bubble sort.
*/
size_t triBulles (std::vector<int> &tab);

/*
    A better version of bubble sort.
*/
size_t triBullesOpti (std::vector<int> &tab);



/*
    Implements a peign sort.
*/
size_t triPeigne(std::vector<int>& tab);



// Using the english wikipedia on quicksort : https://en.wikipedia.org/wiki/Quicksort
extern size_t rapide_nb_comp;
size_t triRapideHandler (std::vector<int> &tab);



/*
    Implements a dumb sort.
*/
size_t triDebile (std::vector<int> &tab);



/*
    Implements an insertion sort
*/
size_t triInsertion (std::vector<int> &tab);