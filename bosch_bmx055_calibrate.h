/*
 * bosch_bmx055_calibrate.h
 *
 *  Created on: Jul 1, 2016
 *      Author: art
 */
#include <stdbool.h>

#ifndef BOSCH_BMX055_CALIBRATE_H_
#define BOSCH_BMX055_CALIBRATE_H_
// Euler sequence: roll(x),pitch(y),yaw(z)
#define RAD2DEG 57.295780
#define DEG2RAD 0.017453

#define dtTarget 20000
#define MXB 0 //9.85
#define MYB 0 //44.69
#define MZB 0 //10.14
#define MXS 1 //0.94
#define MYS 1 //1.06
#define MZS 1 //1.00
#define GXB 0
#define GYB 0
#define GZB 0
#define GYRO_BIAS_DRIFT 0

#define PI 3.1416

struct Sensor_Calibrate{
	float ax,ay,az;
	float gxr,gyr,gzr;
	float gx,gy,gz;
	float mxr,myr,mzr;
	float mx,my,mz;

	float pitch_accl,roll_accl;
	float yaw;
	float MX,MY;
	unsigned int  t_elapse;
	float dt;
};

struct KF{
  bool initial;
  float x0,x1;
  float y;
  float u;
  float M00,M01,M10,M11;
  float W00,W11;
  float v;
  float Z00,Z01,Z10,Z11;
  float K0,K1;
};


void UpdateKF(struct KF *kf, float y, float u);
void InitializeKF(struct KF *kf, float w00, float w11, float v);
void RunKF(struct KF *kf, float dt);
#endif /* BOSCH_BMX055_CALIBRATE_H_ */
