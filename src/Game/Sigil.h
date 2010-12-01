#ifndef GAME_SIGIL_H_
#define GAME_SIGIL_H_

namespace Game{
	class Sigil{
		static unsigned const int
				changement = (0x1),
	            restauration = (0x2),
	            espace = (0x4),
	            augmentation = (0x8),
	            diminution = (0x10),
	            temporaire = (0x20),
	            permanente = (0x40),
	            mouvement = (0x80),
	            locale = (0x100),
	            globale = (0x200),
	            volcanique = (0x400),
	            aquatique = (0x800),
	            aerienne = (0x1000),
	            terrestre = (0x2000),
	            spirtuelle = (0x4000),
	            materielle = (0x8000),
	            energetique = (0x10000),
	            magique = (0x20000),
	            destruction = (0x40000),
	            creation = (0x80000),
	            connaissance = (0x100000),
	            protection = (0x200000),
	            suppresion = (0x400000),
	            curative = (0x800000),
	            vitale = (0x1000000),
	            funeste = (0x2000000);
	};
}

#endif /* GAME_SIGIL_H_ */
