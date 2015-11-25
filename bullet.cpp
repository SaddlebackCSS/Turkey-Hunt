#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game *game; // external global object
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/images/bullet.png"));

    // Connect timer to the bullet
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Every 50 milliseconds the bullet will move
    timer-> start(50);

}

void Bullet::move()
{
    // Get a list of all the items current colliding with this bullet
    QList<QGraphicsItem*> colliding_items = collidingItems();

    // If one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for(int i = 0, n = colliding_items.size(); i < n; i++) {

        // Remove them from the scene
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {

            // Increase the score
            game->score->increase();

            // Removes from the scene
            scene() -> removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // deletes enemy and bullet from heap
            delete colliding_items[i];
            delete this;

            // returns to avoid delete non-existent bullet.
            return;
        }
    }

    // If no collision, the bullet will move up
    setPos(x(), y()-10);

    // Deletes bullet from game once the bullet exits the screen
    if(pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
