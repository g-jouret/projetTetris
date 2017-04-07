#ifndef SUBJECT_H
#define SUBJECT_H

//#include "observer.h"
#include <set>

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class Observer;

/*!
 * \brief Classe abstraite représentant un sujet d'observation du Design Pattern Observer.
 */
class Subject{
public:
    virtual ~Subject() = default;

    /*!
     * \brief Méthode abstraite permettant d'ajouter un \ref Observer.
     * \param observer l'observateur à rajouter
     */
    virtual void addObserver(Observer * observer);

    /*!
     * \brief Méthode abstraite permettant de retirer un \ref Observer.
     * \param observer l'observateur à retirer
     */
    virtual void removeObserver(Observer * observer);

protected:
    Subject() = default;

    /*!
     * \brief Méthode abstraite permettant de demander à tous les \ref Observer
     * de faire une mise à jour des données.
     */
    virtual void notifyObservers();

protected:
    std::set<Observer *> observers_;
    /*!< La liste des \ref Observer de \ref Subject. */
};

} // namespace GJ_GW

#endif // SUBJECT_H
