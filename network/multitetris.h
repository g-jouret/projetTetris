#ifndef MULTITETRIS_H
#define MULTITETRIS_H

#include "../model/tetris.h"
#include "gamemode.h"

/*!
 * \brief Espace de nom de Guillaume Jouret & Guillaume Walravens.
 */
namespace GJ_GW{
class Server;
class Client;
class NetMsg;
/*!
 * \brief Classe qui détrmine le bon fonctionnement du réseaux de tétris.
 *
 * Elle hérite de Tétris.
 */
class MultiTetris : public Tetris{
    Q_OBJECT

    Server *server_;
    /*!< C'est le serveur */
    Client *client_;
    /*!< C'est le client */
    GameMode mode_;
    /*!< Enumération des modes jeux */
    bool ready_;
    /*!< Vrai si le client ou le serveur est prêt */

public:
    /*!
     * \brief Constructeur de tétris
     */
    explicit MultiTetris();
    /*!
     * \brief Accesseur en lecture du nom de la machine selon son adresse ip.
     * \param L'ip de la machine
     * \return le nom de la machine en QString
     */
    QString getHostName(QString &ip) const;
    /*!
     * \brief Accesseur en lecture de l'ip de la machine.
     * \return l'ip de la machine sous forme de QSting
     */
    QString getLocalIP() const;
    /*!
     * \brief Accesseur en lecture du port de la machine.
     */
    unsigned getPort() const;
    /*!
     * \brief Accesseur en lecture du mode de jeux.
     * \return le mode de jeux de la machine
     */
    GameMode getMode() const;
    /*!
     * \brief Accesseur en lecture pour savoir si la machine est prête.
     * \return vrais si la machine est prête
     */
    bool isReady() const;
    /*!
     * \brief Accresseur en écriture de \ref ready.
     */
    void setReady();
    /*!
     * \brief Accresseur en écriture du mode de jeux
     * \param mode le mode de jeux que l'ont veux set
     */
    void setMode(GameMode mode);
    /*!
     * \brief Méthode qui met le game mode à NONE
     */
    void cancelGame();
    /*!
     * \brief Méthode qui initialise le server
     */
    void initServer();
    /*!
     * \brief Méthode qui initialise les client
     * \param hostName le nom de l'host à qui le client se connecte
     * \param port le port de l'host à qui le client se connecte
     */
    void initClient(QString hostName, unsigned port);
    /*!
     * \brief Méthode qui met gameState à NONE
     */
    void connectError();
    /*!
     * \brief Méthode qui envoi un net message pour dire qu'il est prêt.
     */
    void sendReady();
    /*!
     * \brief Méthode qui envoi un net message pour dire que le client cancel la connexion
     */
    void sendCancel();
    /*!
     * \brief Méthode qui envoi un net message pour relancer la partie
     */
    void resume() override;
    /*!
     * \brief Méthode qui envoi un net message pour metre en pause la partie
     */
    void pause() override;
    /*!
     * \brief Méthode qui initialise la partie et envoi les paramtre de la partie à l'autre
     *
     *
     * \param name nom du joueur
     * \param width largeur de la grille
     * \param height hauteur de la grille
     * \param winScore score pour gagner
     * \param winLines lignes pour gagner
     * \param winTime temps pour gagner
     * \param level niveau de dificulté de déprat
     * \param winByScore vrai si la victoire par score est activée
     * \param winByLines vrai si la victoire par nombre de lignes
     * \param winByTime vrai si la victoire par le temps est activer
     */
    void initGame(std::string name, unsigned width, unsigned height, unsigned winScore,
                  unsigned winLines, unsigned winTime, unsigned level, bool winByScore,
                  bool winByLines, bool winByTime) override;
    /*!
     * \brief Méthode qui lance la partie, elle resume la game et génère la 1er brique
     */
    void startGame() override;
    /*!
     * \brief Méthode qui set le gameState
     * \param l'état où le gameState va être set.
     */
    void endGame(int endState);

protected:
    /*!
     * \brief Permet de set le gameState
     * \param état où le gameState va être set
     */
    void setGameState(GameState gameState) override;
    /*!
     * \brief Méthode qui permet de savoir quel ligne envoyer chez l'adversaire.
     *
     * \param top où commencer à check si la ligne est complète
     * \param dropsCount le nombre de drop à compter
     */
    unsigned checkLines(unsigned top, unsigned dropsCount) override;
};

} // namespace GJ_GW

#endif // MULTITETRIS_H
