/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2017  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * util/transform.h
 * SurgeScript Transform Utility
 */

#ifndef _SURGESCRIPT_TRANSFORM_H
#define _SURGESCRIPT_TRANSFORM_H

/* transform type */
typedef struct surgescript_transform_t surgescript_transform_t;

/* we'll make this struct public */
struct surgescript_transform_t
{
    /* A Transform holds position, rotation and scale */
    struct {
        float x, y, z;
    } position;
    
    struct {
        float sx, cx, sy, cy, sz, cz; /* sin & cos of each component */
    } rotation;
    
    struct {
        float x, y, z;
    } scale;
};

/* public API */
surgescript_transform_t* surgescript_transform_create(); /* creates a new identity transform */
surgescript_transform_t* surgescript_transform_destroy(surgescript_transform_t* transform); /* destroys a transform */

/* generic operations */
void surgescript_transform_reset(surgescript_transform_t* t); /* turns t into an identity transform */
void surgescript_transform_copy(surgescript_transform_t* dst, const surgescript_transform_t* src); /* copies src to dst */

/* 2D operations */
void surgescript_transform_setposition2d(surgescript_transform_t* t, float x, float y); /* set position */
void surgescript_transform_setrotation2d(surgescript_transform_t* t, float degrees); /* set rotation */
void surgescript_transform_setscale2d(surgescript_transform_t* t, float sx, float sy); /* set scale */
void surgescript_transform_translate2d(surgescript_transform_t* t, float x, float y); /* translate */
void surgescript_transform_rotate2d(surgescript_transform_t* t, float degrees); /* rotate */
void surgescript_transform_scale2d(surgescript_transform_t* t, float sx, float sy); /* scale */
void surgescript_transform_apply2d(const surgescript_transform_t* t, float* x, float* y); /* applies the transform to a 2D point */
void surgescript_transform_apply2dinverse(const surgescript_transform_t* t, float* x, float* y); /* applies the inverse transform to a 2D point */

/* 3D operations */
/* TODO */

#endif