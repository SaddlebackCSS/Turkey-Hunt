#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set enemy's random position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    // draws the rect
    setPixmap(QPixmap(":/images/Turkey.png"));

    // Connect timer to the bullet
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 milliseconds the bullet will move
    timer-> start(50);

}

void Enemy::move()
{
    // Moves enemy down
    setPos(x(), y()+5);

    // Deletes enemy from game once the enemy exits the screen
    if(pos().y() > 600) {

        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
