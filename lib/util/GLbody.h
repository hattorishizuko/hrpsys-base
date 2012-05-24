#ifndef __GLBODY_H__
#define __GLBODY_H__

#include <vector>
#include <hrpModel/Body.h>
#include "GLlink.h"

class GLcamera;

class GLbody : virtual public hrp::Body
{
public:
    GLbody();
    ~GLbody();
    void setPosture(const double *i_angles);
    void setPosition(double x, double y, double z);
    template<class T>
    void setPosition(const T &p){
        ((GLlink *)rootLink())->setPosition(p);
    }
    void setRotation(const double *R);
    void setRotation(double r, double p, double y);
    void setPosture(const double *i_angles, double *i_pos, double *i_rpy);
    void setPosture(const hrp::dvector& i_q, const hrp::Vector3& i_p,
                    const hrp::Matrix33& i_R);
    void draw();
    GLcamera *findCamera(const char *i_name);
    static void useAbsTransformToDraw();

private:
    static bool m_useAbsTransformToDraw;
};

#endif