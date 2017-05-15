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

class MultiTetris : public Tetris{
    Q_OBJECT
    /*QTcpServer *server_;
    QTcpSocket *socket_;*/
    Server *server_;
    Client *client_;
    GameMode mode_;
    //quint16 messageSize_;
    bool ready_;

public:
    explicit MultiTetris();
    QString getHostName(QString &ip) const;
    QString getLocalIP() const;
    unsigned getPort() const;
    GameMode getMode() const;
    //bool isListening() const;
    bool isReady() const;
    void setReady();
    void cancelGame();
    void setMode(GameMode mode);
    void initServer();
    void initClient(QString hostName, unsigned port);
    void connectError();
    //QString getNotif() const;
    //bool isClientConnected() const;
    //QString clientError() const;

    void sendReady();
    void sendCancel();

    void resume() override;
    void pause() override;
    void initGame(std::string name, unsigned width, unsigned height, unsigned winScore,
                  unsigned winLines, unsigned winTime, unsigned level, bool winByScore,
                  bool winByLines, bool winByTime) override;
    void startGame() override;
    void endGame(int endState, int score, int nbLines);

protected:
    void setGameState(GameState gameState) override;
    //QString serverError() const;

/*private:
    void sendData(const NetMsg &msg);
    void reactToFirstMsg(NetMsg &netMsg);
    void reactToAskSettings();*/

//signals:
    //void newClient();
/*
private slots:
    void connection();
    void disconnection();
    void dataReception();*/
};

} // namespace GJ_GW

#endif // MULTITETRIS_H
