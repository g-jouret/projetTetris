#ifndef DISPLAY_H
#define DISPLAY_H

enum {
    ENG,
    FR
};

enum {
    LBNAME,
    LBSCORE,
    LBLINES
};

#endif // DISPLAY_H
/*
#include <string>

struct DisplayFr{
    std::string lbName = "Joueur :";
    std::string lbScore = "Score :";
    std::string lbLines = "Nombre de lignes :";
    std::string lbTimer = "Temps écoulé :";
    std::string btnUp = "Haut";
    std::string btnDown = "Bas";
    std::string btnLeft = "Gauche";
    std::string btnRight = "Droite";
};

#endif // DISPLAYFR_H
struct Display {
    struct lbName {
        std::string fr {"Joueur :"};
        std::string eng {"Player :"};
    };
    struct lbScore {
        std::string fr {"Score :"};
        std::string eng {"Score :"};
    };
    struct lbLines {
        std::string fr {"Nombre de lignes :"};
        std::string eng {"Amount of lines"};
    };
    struct lbTimer {
        std::string fr {"Temps écoulé :"};
        std::string eng {"Time elapsed"};
    };
    struct btnUp {
        std::string fr {"Haut"};
        std::string eng {"Up"};
    };
    struct btnDown {
        std::string fr {"Bas"};
        std::string eng {"Down"};
    };
    struct btnLeft {
        std::string fr {"Gauche"};
        std::string eng {"Left"};
    };
    struct btnRight {
        std::string fr {"Droite"};
        std::string eng {"Right"};
    };
};
struct Display {
    enum class lbName {
        fr = "Joueur :",
        eng = "Player :"
    };
    enum class lbScore {
        fr = "Score :",
        eng = "Score :"
    };
    enum class lbLines {
        fr = "Nombre de lignes :",
        eng = "Amount of lines"
    };
    enum class lbTimer {
        fr = "Temps écoulé :",
        eng = "Time elapsed"
    };
    enum class btnUp {
        fr = "Haut",
        eng = "Up"
    };
    enum class btnDown {
        fr = "Bas",
        eng = "Down"
    };
    enum class btnLeft {
        fr = "Gauche",
        eng = "Left"
    };
    enum class btnRight {
        fr = "Droite",
        eng = "Right"
    };
};
*/
