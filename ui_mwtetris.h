/********************************************************************************
** Form generated from reading UI file 'mwtetris.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWTETRIS_H
#define UI_MWTETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWTetris
{
public:
    QAction *action_Nouveau;
    QAction *action_Quitter;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *infoBox;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QSpacerItem *horizontalSpacer;
    QLabel *lbPlayerName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbScore;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbPlayerScore;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbLines;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lbPlayerLines;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbTimer;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lbTime;
    QSpacerItem *verticalSpacer;
    QGridLayout *boardNext;
    QPushButton *btnStart;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnUp;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDown;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbLevel;
    QLabel *lbLevelGame;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QWidget *gridLayoutWidget;
    QGridLayout *boardGrid;
    QWidget *winWidget;
    QLabel *lbEnd;
    QMenuBar *menuBar;
    QMenu *menu_Jeu;

    void setupUi(QMainWindow *MWTetris)
    {
        if (MWTetris->objectName().isEmpty())
            MWTetris->setObjectName(QStringLiteral("MWTetris"));
        MWTetris->resize(646, 634);
        MWTetris->setStyleSheet(QStringLiteral("background: QLinearGradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #eef, stop: 1 #ccf);"));
        MWTetris->setIconSize(QSize(2, 2));
        action_Nouveau = new QAction(MWTetris);
        action_Nouveau->setObjectName(QStringLiteral("action_Nouveau"));
        action_Quitter = new QAction(MWTetris);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralWidget = new QWidget(MWTetris);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 0, 251, 611));
        infoBox = new QVBoxLayout(layoutWidget);
        infoBox->setSpacing(10);
        infoBox->setContentsMargins(11, 11, 11, 11);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setSizeConstraint(QLayout::SetNoConstraint);
        infoBox->setContentsMargins(20, 20, 20, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbName = new QLabel(layoutWidget);
        lbName->setObjectName(QStringLiteral("lbName"));
        lbName->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbPlayerName = new QLabel(layoutWidget);
        lbPlayerName->setObjectName(QStringLiteral("lbPlayerName"));

        horizontalLayout->addWidget(lbPlayerName);


        infoBox->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbScore = new QLabel(layoutWidget);
        lbScore->setObjectName(QStringLiteral("lbScore"));
        lbScore->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout_2->addWidget(lbScore);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lbPlayerScore = new QLabel(layoutWidget);
        lbPlayerScore->setObjectName(QStringLiteral("lbPlayerScore"));

        horizontalLayout_2->addWidget(lbPlayerScore);


        infoBox->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbLines = new QLabel(layoutWidget);
        lbLines->setObjectName(QStringLiteral("lbLines"));
        lbLines->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout_7->addWidget(lbLines);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        lbPlayerLines = new QLabel(layoutWidget);
        lbPlayerLines->setObjectName(QStringLiteral("lbPlayerLines"));

        horizontalLayout_7->addWidget(lbPlayerLines);


        infoBox->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lbTimer = new QLabel(layoutWidget);
        lbTimer->setObjectName(QStringLiteral("lbTimer"));
        lbTimer->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout_6->addWidget(lbTimer);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        lbTime = new QLabel(layoutWidget);
        lbTime->setObjectName(QStringLiteral("lbTime"));

        horizontalLayout_6->addWidget(lbTime);


        infoBox->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer);

        boardNext = new QGridLayout();
        boardNext->setSpacing(5);
        boardNext->setObjectName(QStringLiteral("boardNext"));
        boardNext->setSizeConstraint(QLayout::SetMinimumSize);

        infoBox->addLayout(boardNext);

        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setStyleSheet(QLatin1String("QPushButton {\n"
"color: BLACK;\n"
"font-weight: bold;\n"
"border: none;\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.0100503 rgba(255, 0, 0, 255), stop:0.1 rgba(255, 0, 0, 255), stop:0.2 rgba(255, 0, 0, 255), stop:0.3 rgba(255, 0, 0, 255), stop:0.4 rgba(255, 0, 0, 255), stop:0.502513 rgba(164, 0, 0, 205), stop:0.52 rgba(139, 0, 0, 205), stop:0.562814 rgba(0, 0, 0, 205), stop:0.6 rgba(255, 180, 180, 97), stop:1 rgba(255, 255, 255, 0));\n"
"max-width: 150px;\n"
"height: 150px;\n"
"}"));

        infoBox->addWidget(btnStart);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));

        infoBox->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnUp = new QPushButton(layoutWidget);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(btnUp->sizePolicy().hasHeightForWidth());
        btnUp->setSizePolicy(sizePolicy);
        btnUp->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_3->addWidget(btnUp);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        infoBox->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnLeft = new QPushButton(layoutWidget);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        sizePolicy.setHeightForWidth(btnLeft->sizePolicy().hasHeightForWidth());
        btnLeft->setSizePolicy(sizePolicy);
        btnLeft->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_4->addWidget(btnLeft);

        btnRight = new QPushButton(layoutWidget);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        btnRight->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_4->addWidget(btnRight);


        infoBox->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        btnDown = new QPushButton(layoutWidget);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        sizePolicy.setHeightForWidth(btnDown->sizePolicy().hasHeightForWidth());
        btnDown->setSizePolicy(sizePolicy);
        btnDown->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_5->addWidget(btnDown);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        infoBox->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lbLevel = new QLabel(layoutWidget);
        lbLevel->setObjectName(QStringLiteral("lbLevel"));
        lbLevel->setEnabled(true);

        horizontalLayout_8->addWidget(lbLevel);

        lbLevelGame = new QLabel(layoutWidget);
        lbLevelGame->setObjectName(QStringLiteral("lbLevelGame"));

        horizontalLayout_8->addWidget(lbLevelGame);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        infoBox->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_3);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 391, 611));
        boardGrid = new QGridLayout(gridLayoutWidget);
        boardGrid->setSpacing(3);
        boardGrid->setContentsMargins(11, 11, 11, 11);
        boardGrid->setObjectName(QStringLiteral("boardGrid"));
        boardGrid->setSizeConstraint(QLayout::SetNoConstraint);
        boardGrid->setContentsMargins(20, 20, 20, 20);
        winWidget = new QWidget(centralWidget);
        winWidget->setObjectName(QStringLiteral("winWidget"));
        winWidget->setGeometry(QRect(-1, 169, 641, 201));
        winWidget->setAutoFillBackground(false);
        winWidget->setStyleSheet(QStringLiteral("QWidget{background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 176, 0, 69), stop:0.375 rgba(255, 223, 0, 69), stop:0.423533 rgba(255, 223, 0, 145), stop:0.45 rgba(255, 214, 0, 208), stop:0.477581 rgba(255, 219, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.547739 rgba(255, 214, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(251, 255, 0, 69), stop:1 rgba(255, 242, 0, 69));}"));
        lbEnd = new QLabel(winWidget);
        lbEnd->setObjectName(QStringLiteral("lbEnd"));
        lbEnd->setGeometry(QRect(20, 40, 601, 131));
        lbEnd->setStyleSheet(QLatin1String("QLabel{\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"}"));
        lbEnd->setAlignment(Qt::AlignCenter);
        MWTetris->setCentralWidget(centralWidget);
        layoutWidget->raise();
        gridLayoutWidget->raise();
        lbLevel->raise();
        lbLevelGame->raise();
        btnStart->raise();
        winWidget->raise();
        menuBar = new QMenuBar(MWTetris);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 20));
        menu_Jeu = new QMenu(menuBar);
        menu_Jeu->setObjectName(QStringLiteral("menu_Jeu"));
        MWTetris->setMenuBar(menuBar);

        menuBar->addAction(menu_Jeu->menuAction());
        menu_Jeu->addAction(action_Nouveau);
        menu_Jeu->addAction(action_Quitter);

        retranslateUi(MWTetris);

        QMetaObject::connectSlotsByName(MWTetris);
    } // setupUi

    void retranslateUi(QMainWindow *MWTetris)
    {
        MWTetris->setWindowTitle(QApplication::translate("MWTetris", "Tetris", Q_NULLPTR));
        action_Nouveau->setText(QApplication::translate("MWTetris", "&Nouveau", Q_NULLPTR));
        action_Nouveau->setShortcut(QApplication::translate("MWTetris", "Ctrl+N", Q_NULLPTR));
        action_Quitter->setText(QApplication::translate("MWTetris", "&Quitter", Q_NULLPTR));
        action_Quitter->setShortcut(QApplication::translate("MWTetris", "Ctrl+Q", Q_NULLPTR));
        lbName->setText(QApplication::translate("MWTetris", "lbName", Q_NULLPTR));
        lbPlayerName->setText(QApplication::translate("MWTetris", "lbPlayerName", Q_NULLPTR));
        lbScore->setText(QApplication::translate("MWTetris", "lbScore", Q_NULLPTR));
        lbPlayerScore->setText(QApplication::translate("MWTetris", "00", Q_NULLPTR));
        lbLines->setText(QApplication::translate("MWTetris", "lbLines", Q_NULLPTR));
        lbPlayerLines->setText(QApplication::translate("MWTetris", "00", Q_NULLPTR));
        lbTimer->setText(QApplication::translate("MWTetris", "lbTimer", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        lbTime->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lbTime->setText(QApplication::translate("MWTetris", "00:00", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MWTetris", "COMMENCER", Q_NULLPTR));
        btnUp->setText(QApplication::translate("MWTetris", "Haut", Q_NULLPTR));
        btnUp->setShortcut(QApplication::translate("MWTetris", "Up", Q_NULLPTR));
        btnLeft->setText(QApplication::translate("MWTetris", "Gauche", Q_NULLPTR));
        btnLeft->setShortcut(QApplication::translate("MWTetris", "Left", Q_NULLPTR));
        btnRight->setText(QApplication::translate("MWTetris", "Droite", Q_NULLPTR));
        btnRight->setShortcut(QApplication::translate("MWTetris", "Right", Q_NULLPTR));
        btnDown->setText(QApplication::translate("MWTetris", "Bas", Q_NULLPTR));
        btnDown->setShortcut(QApplication::translate("MWTetris", "Down", Q_NULLPTR));
        lbLevel->setText(QApplication::translate("MWTetris", "lbLevel", Q_NULLPTR));
        lbLevelGame->setText(QApplication::translate("MWTetris", "0", Q_NULLPTR));
        lbEnd->setText(QApplication::translate("MWTetris", "TextLabel", Q_NULLPTR));
        menu_Jeu->setTitle(QApplication::translate("MWTetris", "&Jeu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MWTetris: public Ui_MWTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWTETRIS_H
