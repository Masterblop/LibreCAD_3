#include "ellipse.h"

using namespace lc;

Ellipse::Ellipse(const geo::Coordinate& center, const geo::Coordinate& majorP, double minorRadius, double startAngle, double endAngle)
    : geo::Ellipse(center, majorP, minorRadius, startAngle, endAngle) {

}

Ellipse::Ellipse(const geo::Coordinate& center, const geo::Coordinate& majorP, double minorRadius, double startAngle, double endAngle, const QList<shared_ptr<const MetaType> >& metaTypes)
    : CADEntity(metaTypes),  geo::Ellipse(center, majorP, minorRadius, startAngle, endAngle) {
}

shared_ptr<const CADEntity> Ellipse::move(const geo::Coordinate& offset, const geo::Coordinate& rotation_center, const double& rotation_angle) const {
//    Ellipse* newellipse = new Ellipse((this->center().rotate(rotation_center, rotation_angle)) + offset,
//                                          (this->majorP().rotate(rotation_center, rotation_angle)) + offset,
//                                          this->minorRadius() , this->startAngle() + rotation_angle,
//                                          this->endAngle() + rotation_angle);
//    newellipse->setID(this->id());
//    shared_ptr<const Ellipse> newEllipse = shared_ptr<const Ellipse>(newellipse);
//    return newEllipse;
    return rotate(offset, rotation_center, rotation_angle, 1);
}

shared_ptr<const CADEntity> Ellipse::copy(const geo::Coordinate& offset, const geo::Coordinate& rotation_center, const double& rotation_angle) const {
//    Ellipse* newellipse = new Ellipse((this->center().rotate(rotation_center, rotation_angle)) + offset,
//                                          (this->majorP().rotate(rotation_center, rotation_angle)) + offset,
//                                          this->minorRadius() , this->startAngle() + rotation_angle,
//                                          this->endAngle() + rotation_angle);
//    shared_ptr<const Ellipse> newEllipse = shared_ptr<const Ellipse>(newellipse);
//    return newEllipse;
        return rotate(offset, rotation_center, rotation_angle, 0);
}

shared_ptr<const CADEntity> Ellipse::rotate(const geo::Coordinate& offset, const geo::Coordinate &rotation_center, const double& rotation_angle, const bool with_same_id) const {
    Ellipse* newellipse = new Ellipse((this->center().rotate(rotation_center, rotation_angle)) + offset,
                                          (this->majorP().rotate(rotation_center, rotation_angle)) + offset,
                                          this->minorRadius() , this->startAngle() + rotation_angle,
                                          this->endAngle() + rotation_angle);
    if (with_same_id == true) {
        newellipse->setID(this->id());
    }
    shared_ptr<const Ellipse> newEllipse = shared_ptr<const Ellipse>(newellipse);
    return newEllipse;
}
