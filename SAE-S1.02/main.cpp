#include <iostream>
#include <vector>
#include "fonctions.h"

#define N_MAX 8
#define FILE_NAME "output-sort.csv"
#define LOOKUP_SIZE (sizeof (lookup) / sizeof (*lookup))

typedef struct lookup_t {
    size_t (*ptr) (std::vector<int> &);
    std::string name;

} lookup_t;

lookup_t lookup[] = {
    {
        triSelection,
        "Tri Sélectif"
    },
    {
        triBulles,
        "Tri à Bulles"
    },
    {
        triBullesOpti,
        "Tri à Bulles Optimisé"
    },
    {
        triPeigne,
        "Tri Peigne"
    },
   {
        triRapideHandler,
        "Tri Rapide"
    },
    {
        triInsertion,
        "Tri par Insertion"
    },
    {
        triDebile,          // It is not recommended to run this function with N_MAX set past 8
        "Tri Débile"
    }
};





int main () {
	std::string header = "N;Aleat;PresqueTri;PresqueTriDeb;PresqueTriDebFin;PresqueTriFin\n";
	std::ofstream csvSelect(FILE_NAME);

    for (size_t i = 0; i < LOOKUP_SIZE; i++) {
        if (!csvSelect.is_open())
            csvSelect.open(FILE_NAME, std::ios_base::app);
	    csvSelect << lookup[i].name << "\n" << header;

        for (size_t N = 2; N <= N_MAX; N *= 2) {
            csvSelect << N << ';';
            std::vector<int> tab;

            tab = initTabAleat(N);
            csvSelect << lookup[i].ptr (tab) << ';';
            verifTri(tab);

            tab = initTabPresqueTri(N);
            csvSelect << lookup[i].ptr(tab) << ';';
            verifTri(tab);

            tab = initTabPresqueTriDeb(N);
            csvSelect << lookup[i].ptr(tab) << ';';
            verifTri(tab);

            tab = initTabPresqueTriFin(N);
            csvSelect << lookup[i].ptr(tab) << ';';
            verifTri(tab);

            tab = initTabPresqueTriDebFin(N);
            csvSelect << lookup[i].ptr(tab) << std::endl;
            verifTri(tab);
        }
        
        csvSelect << std::endl;
        csvSelect.close();
    }
}
