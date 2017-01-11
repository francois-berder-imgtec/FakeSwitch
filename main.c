#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define COUNT               (10)
#define SWITCH_1_CODE       (0x101)
#define SWITCH_2_CODE       (0x102)

static int send_switch_event(int fd, int code, uint16_t pressed)
{
    struct input_event event[2];
    event[0].type = EV_KEY;
    event[0].code = code;
    event[0].value = pressed;
    gettimeofday(&event[0].time, NULL);

    /* Creating SYN event */
    memset(&event[1], 0, sizeof(struct input_event));
    event[1].time = event[0].time;

    return write(fd, event, sizeof(event));
}

int main(void)
{
    int i;
    int fd = open("/dev/input/event0", O_WRONLY | O_SYNC);
    if (fd < 0) {
        fprintf(stderr, "Failed to open /dev/input/event0.\n");
        return -1;
    }

    for (i = 0; i < COUNT; ++i) {
        send_switch_event(fd, SWITCH_1_CODE, 1);
        send_switch_event(fd, SWITCH_1_CODE, 0);
        send_switch_event(fd, SWITCH_2_CODE, 1);
        send_switch_event(fd, SWITCH_2_CODE, 0);

        sleep(1);
    }
    close(fd);

    return 0;
}
