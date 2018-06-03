/* Generated by wayland-scanner 1.15.90 */

#include <stdlib.h>
#include <stdint.h>
#include "wayland-util.h"

#ifndef __has_attribute
# define __has_attribute(x) 0  /* Compatibility with non-clang compilers. */
#endif

#if (__has_attribute(visibility) || defined(__GNUC__) && __GNUC__ >= 4)
#define WL_PRIVATE __attribute__ ((visibility("hidden")))
#else
#define WL_PRIVATE
#endif

extern const struct wl_interface wl_output_interface;
extern const struct wl_interface zwf_output_v1_interface;

static const struct wl_interface *types[] = {
	NULL,
	NULL,
	NULL,
	&zwf_output_v1_interface,
	&wl_output_interface,
};

static const struct wl_message zwf_output_v1_requests[] = {
	{ "set_position", "ii", types + 0 },
	{ "set_mode", "iii", types + 0 },
	{ "set_transform", "u", types + 0 },
	{ "set_scale", "f", types + 0 },
};

WL_PRIVATE const struct wl_interface zwf_output_v1_interface = {
	"zwf_output_v1", 1,
	4, zwf_output_v1_requests,
	0, NULL,
};

static const struct wl_message zwf_output_manager_v1_requests[] = {
	{ "get_wf_output", "no", types + 3 },
};

WL_PRIVATE const struct wl_interface zwf_output_manager_v1_interface = {
	"zwf_output_manager_v1", 1,
	1, zwf_output_manager_v1_requests,
	0, NULL,
};

