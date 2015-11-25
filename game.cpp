#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent) {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);

    // Turns off all scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // Create main player
    mainPlayer = new Player();
    mainPlayer->setPos(400,450);

    // Make the main player focusable
    mainPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
    mainPlayer->setFocus();

    // Add the player to the scene
    scene->addItem(mainPlayer);

    // Create the score/health
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health ->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // Spawns enemies
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), mainPlayer, SLOT(spawn()));
    timer->start(2000);

    // Play background music
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/Vince Guaraldi Trio - Thanksgiving Theme.mp3"));
    music->setVolume(20);
    music->play();

}

