/********************************************************************************
** Form generated from reading UI file 'mwtetris.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWTETRIS_H
#define UI_MWTETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWTetris
{
public:
    QAction *action_Nouveau;
    QAction *action_Fermer;
    QAction *action_Quitter;
    QAction *action_Proposition;
    QWidget *centralWidget;
    QTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbScore;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbPlayerScore;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QSpacerItem *horizontalSpacer;
    QLabel *lbPlayerName;
    QMenuBar *menuBar;
    QMenu *menu_Jeu;

    void setupUi(QMainWindow *MWTetris)
    {
        if (MWTetris->objectName().isEmpty())
            MWTetris->setObjectName(QStringLiteral("MWTetris"));
        MWTetris->resize(481, 577);
        action_Nouveau = new QAction(MWTetris);
        action_Nouveau->setObjectName(QStringLiteral("action_Nouveau"));
        action_Fermer = new QAction(MWTetris);
        action_Fermer->setObjectName(QStringLiteral("action_Fermer"));
        action_Fermer->setEnabled(false);
        action_Quitter = new QAction(MWTetris);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        action_Proposition = new QAction(MWTetris);
        action_Proposition->setObjectName(QStringLiteral("action_Proposition"));
        action_Proposition->setCheckable(true);
        action_Proposition->setEnabled(false);
        centralWidget = new QWidget(MWTetris);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 30, 256, 491));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 100, 148, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lbScore = new QLabel(layoutWidget);
        lbScore->setObjectName(QStringLiteral("lbScore"));

        horizontalLayout_2->addWidget(lbScore);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lbPlayerScore = new QLabel(layoutWidget);
        lbPlayerScore->setObjectName(QStringLiteral("lbPlayerScore"));

        horizontalLayout_2->addWidget(lbPlayerScore);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(310, 50, 148, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lbName = new QLabel(widget);
        lbName->setObjectName(QStringLiteral("lbName"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbPlayerName = new QLabel(widget);
        lbPlayerName->setObjectName(QStringLiteral("lbPlayerName"));

        horizontalLayout->addWidget(lbPlayerName);

        MWTetris->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MWTetris);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 20));
        menu_Jeu = new QMenu(menuBar);
        menu_Jeu->setObjectName(QStringLiteral("menu_Jeu"));
        MWTetris->setMenuBar(menuBar);

        menuBar->addAction(menu_Jeu->menuAction());
        menu_Jeu->addAction(action_Nouveau);
        menu_Jeu->addAction(action_Fermer);
        menu_Jeu->addAction(action_Quitter);

        retranslateUi(MWTetris);

        QMetaObject::connectSlotsByName(MWTetris);
    } // setupUi

    void retranslateUi(QMainWindow *MWTetris)
    {
        MWTetris->setWindowTitle(QApplication::translate("MWTetris", "Tetris", 0));
        action_Nouveau->setText(QApplication::translate("MWTetris", "&Nouveau", 0));
        action_Nouveau->setShortcut(QApplication::translate("MWTetris", "Ctrl+N", 0));
        action_Fermer->setText(QApplication::translate("MWTetris", "&Fermer", 0));
        action_Fermer->setShortcut(QApplication::translate("MWTetris", "Ctrl+X", 0));
        action_Quitter->setText(QApplication::translate("MWTetris", "&Quitter", 0));
        action_Quitter->setShortcut(QApplication::translate("MWTetris", "Ctrl+Q", 0));
        action_Proposition->setText(QApplication::translate("MWTetris", "&Proposition", 0));
        action_Proposition->setShortcut(QApplication::translate("MWTetris", "Ctrl+T", 0));
        lbScore->setText(QApplication::translate("MWTetris", "TextLabel", 0));
        lbPlayerScore->setText(QApplication::translate("MWTetris", "TextLabel", 0));
        lbName->setText(QApplication::translate("MWTetris", "TextLabel", 0));
        lbPlayerName->setText(QApplication::translate("MWTetris", "TextLabel", 0));
        menu_Jeu->setTitle(QApplication::translate("MWTetris", "&Jeu", 0));
    } // retranslateUi

};

namespace Ui {
    class MWTetris: public Ui_MWTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWTETRIS_H
