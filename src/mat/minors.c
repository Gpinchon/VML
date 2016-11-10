/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 01:10:48 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 01:52:04 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_mat2	mat2_minors(const t_mat2 m)
{
	return ((t_mat2){.m = {
		m.m[3], m.m[2],
		m.m[1], m.m[0]
	}});
}

t_mat3	mat3_minors(const t_mat3 m)
{
	float	det[9];

	det[0] = mat2_determinant((t_mat2){.m = {m.m[4], m.m[5], m.m[7], m.m[8]}});
	det[1] = mat2_determinant((t_mat2){.m = {m.m[3], m.m[5], m.m[6], m.m[8]}});
	det[2] = mat2_determinant((t_mat2){.m = {m.m[3], m.m[4], m.m[6], m.m[7]}});
	det[3] = mat2_determinant((t_mat2){.m = {m.m[1], m.m[2], m.m[7], m.m[8]}});
	det[4] = mat2_determinant((t_mat2){.m = {m.m[0], m.m[2], m.m[6], m.m[8]}});
	det[5] = mat2_determinant((t_mat2){.m = {m.m[0], m.m[1], m.m[6], m.m[7]}});
	det[6] = mat2_determinant((t_mat2){.m = {m.m[1], m.m[2], m.m[4], m.m[5]}});
	det[7] = mat2_determinant((t_mat2){.m = {m.m[0], m.m[2], m.m[3], m.m[5]}});
	det[8] = mat2_determinant((t_mat2){.m = {m.m[0], m.m[1], m.m[3], m.m[4]}});
	return ((t_mat3){.m = {
		det[0], det[1], det[2],
		det[3], det[4], det[5],
		det[6], det[7], det[8]}});
}

/*
(t_mat4){ .m = {
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11,
		12, 13, 14, 15
	}});
*/

t_mat4	mat4_minors(const t_mat4 m)
{
	float	det[16];

	det[0] = mat3_determinant((t_mat3){.m = {
		m.m[5], m.m[6], m.m[7],
		m.m[9], m.m[10], m.m[11],
		m.m[13], m.m[14], m.m[15]}});
	det[1] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[6], m.m[7],
		m.m[8], m.m[10], m.m[11],
		m.m[12], m.m[14], m.m[15]}});
	det[2] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[7],
		m.m[8], m.m[9], m.m[11],
		m.m[12], m.m[13], m.m[15]}});
	det[3] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[4] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[5] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[6] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[7] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[8] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[9] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[10] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[11] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[12] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[13] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[14] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[15] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	det[16] = mat3_determinant((t_mat3){.m = {
		m.m[4], m.m[5], m.m[5],
		m.m[5], m.m[6], m.m[7],
		m.m[4], m.m[5], m.m[5]}});
	return ((t_mat4){ .m = {
		det[0], det[1], det[2],
		det[3], det[4], det[5],
		det[6], det[7], det[8]}});
}
