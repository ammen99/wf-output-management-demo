#include "proto.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct zwf_output_manager_v1 *manager;
struct zwf_output_v1 *output;

uint32_t transform;
double scale;

void registry_add_object(void* vv, struct wl_registry *registry, uint32_t name,
        const char *interface, uint32_t vvv)
{
    printf("new registry iface %s\n", interface);
    if (strcmp(interface, zwf_output_manager_v1_interface.name) == 0)
    {
        printf("bind it\n");
        manager = (struct zwf_output_manager_v1*)
            wl_registry_bind(registry, name, &zwf_output_manager_v1_interface, 1u);
    } else if (strcmp(interface, wl_output_interface.name) == 0)
    {
        struct wl_output *wl_output = (struct wl_output*)
            wl_registry_bind(registry, name, &wl_output_interface, vvv);
        output = (struct zwf_output_v1*)
            zwf_output_manager_v1_get_wf_output(manager, wl_output);

        printf("got output\n");

        zwf_output_v1_set_scale(output, wl_fixed_from_double(scale));
        //zwf_output_v1_set_transform(output, transform);
    }
}

void registry_remove_object(void* stupid, struct wl_registry* st, uint32_t stu)
{
}

static struct wl_registry_listener registry_listener =
{
    &registry_add_object,
    &registry_remove_object
};

int main()
{
    scanf("%lf", &scale);
    auto display = wl_display_connect(NULL);
    auto registry = wl_display_get_registry(display);

    wl_registry_add_listener(registry, &registry_listener, NULL);
    wl_display_roundtrip(display);
    wl_registry_destroy(registry);

    while(1) {
        if (wl_display_dispatch(display) < 0)
            break;
        sleep(1);
    }
}
