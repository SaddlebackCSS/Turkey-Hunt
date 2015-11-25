#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/ie_shot_gun-luminalace-770179786.mp3"));

    setPixmap(QPixmap(":/images/thanksgiving man.png"));

}

void Player::keyPressEvent(QKeyEvent *event) {
    const int MOVE_POSITION = 30;
    if(event -> key() == Qt::Key_Left) {
        if(pos().x() > 0) {
        setPos(x() - MOVE_POSITION, y());
        }
    }
    else if (event -> key() == Qt::Key_Right) {
        if(pos().x() + 100 < 800) {
        setPos(x() + MOVE_POSITION, y());
        }
    }
//    else if (event -> key() == Qt::Key_Up) {
//        setPos(x(), y() - MOVE_POSITION);
//    }
//    else if (event -> key() == Qt::Key_Down) {
//        setPos(x(), y() + MOVE_POSITION);
//    }
    else if (event -> key() == Qt::Key_Space) {
        // Creates a bullet if user presses space
        Bullet * bullet = new Bullet();
        bullet -> setPos(x(), y());
        bullet->moveBy(this->boundingRect().width()/2,0);
        scene() -> addItem(bullet);

        // play bulletSound
        if(bulletSound->state() == QMediaPlayer::PlayingState) {
            bulletSound->setPosition(0);
        }
        else if(bulletSound->state() == QMediaPlayer::StoppedState) {
            bulletSound->play();
        }
    }
}

void Player::spawn()
{
    // create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
