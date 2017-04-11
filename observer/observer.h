#ifndef OBSERVER_H
#define OBSERVER_H

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{

class Subject;

/*!
 * \brief Classe abstraite représentant un observateur du Design Pattern Observer.
 */
class Observer{
public:
    /*!
     * \brief Méthode virtuelle permettant à l'observateur de récupérer les données de son \ref Subject.
     * \param subject le sujet d'observation de l'observateur
     */
    virtual void update(Subject * subject) = 0;

    virtual ~Observer() = default;
};

} // namespace GJ_GW

#endif // OBSERVER_H
