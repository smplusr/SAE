#include "console.hh"


lookup_v intlookup_v = {
	{ "--input", inputset_f },
	{ "--output", outputset_f },
	{ "--palette", paletset_f },
};



bool lookexist_f (lookup_v &in_v, std::string in_s) {
	for (lookup_t tmp_t : in_v)
		if (tmp_t.ref_s == in_s)
			return true;
	return false;
}


void (*lookget_f (lookup_v &in_v, std::string in_s)) (std::string in_s) {
	for (lookup_t tmp_t : in_v)
		if (tmp_t.ref_s == in_s)
			return tmp_t.ptr_f;
	return nullptr;
}


void manual_f () {
	std::cout << "Usage :\n"
		  << "pgm2txt [options]\n\n"
		  << "Options :\n\n"
		  << "--input fichier 		Spécifie le fichier image à convertir\n"
		  << "				Si ce paramètre n'est pas spécifié, le fichier est demandé via la\n"
		  << "				console.\n\n"
		  << "--output fichier		Spécifie le nom du fichier texte qui contiendra l'Ascii Art.\n"
		  << "				Si ce paramètre n'est pas spécifié, l'Ascii Art est sortie dans la\n"
		  << "				console.\n\n"
		  << "--palette fichier 	Spécifie un fichier texte contenant la palette de couleur Ascii.\n"
		  << "				Chaque ligne du fichier contient un charactère en UTF-8, du plus\n"
		  << "				sombre au plus clair.\n"
		  << "				Si ce paramètre n'est pas spécifié, la palette par défaut est\n"
		  << "				\"W\", \"w\", \"l\", \"i\", \":\", \",\", \".\", \" \"\n\n"
		  << "--help 			Affiche cette aide.\n\n"
		  << "--width nombre		Spécifie la largeur max de l'Ascii Art.\n"
		  << "				Si ce paramètre n'est pas spécifié, aucune limite n'est fixée.\n"
		  << "				Voir Remarques.\n\n"
		  << "--height nombre 		Spécifie la hauteur max de l'Ascii Art.\n"
		  << "				Si ce paramètre n'est pas spécifié, aucune limite n'est fixée.\n"
		  << "				Voir Remarques.\n\n"
		  << "Remarques :\n"
		  << "Quelles que soient les valeurs des options --width et --height, la taille de l'Ascii Art\n"
		  << "est bornée par la taille de l'image en entrée. La taille de l'ascii art conserve\n"
		  << "toujours le même ratio que l'image d'entrée, les valeurs des options --width et --height\n"
		  << "ne sont que des maximums.\n";
}
