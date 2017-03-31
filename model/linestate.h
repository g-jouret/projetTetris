#ifndef LINESTATE
#define LINESTATE

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

/*!
 * \brief Énumération fortement typée pour représenter l'état d'une ligne de la grille de jeu.
 */
enum class LineState{

    /*! représente une ligne vide. */
    EMPTY,
    /*! Représente une ligne remplie. */
    FILL,
    /*! Représente une ligne n'étant ni vide ni totalement remplie. */
    BOTH,
    /*! Représente une ligne dont l'état n'est pas encore défini. */
    NONE
};

} // namespace GJ_GW

#endif // LINESTATE

