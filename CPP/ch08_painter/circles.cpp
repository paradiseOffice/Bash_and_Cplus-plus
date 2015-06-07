#include <QtGui>
#include ""

QPainter painter(this);
painter.setRenderHint(QPainter::Antialiasing, true);
painter.setPen(QPen(Qt::magenta, 12, Qt::DashDotLine, Qt:: RoundCap));
painter.setBrush(QBrush(Qt::black, Qt::DensePattern));
painter.drawEllipse(80,80,400,240);

// Draw a pie segment - a pacman shaped object
QPainter painter(this);
painter.setRenderHint(QPainter::Antialiasing, true);
painter.setPen(QPen(Qt::black, 15, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
painter.setBrush(QBrush(Qt::magenta, Qt::SolidPattern,));
painter.drawPie(80,80, 400, 240, 60 * 16, 270 * 16);

// A bezier curve
QPainter painter(this);
painter.setRenderHint(QPainter::Antialiasing, true);

QPainterPath path;
path.moveTo(80, 320);
path.cubicTo(200, 80, 320, 80, 480, 320);

painter.setPen(QPen(Qt::magenta, 8));
painter.drawPath(path);
