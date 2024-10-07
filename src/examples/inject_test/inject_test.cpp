#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/posix.h>

#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>

#include <uORB/uORB.h>
#include <uORB/topics/test.h>

extern "C" __EXPORT int inject_test_main(int argc, char *argv[]);

int inject_test_main(int argc, char *argv[])
{
    PX4_INFO("Hello, I am only a test program");

    // Declare structure to store data that will be sent
    struct test_s test;

    // Clear the structure by filling it with 0s in memory
    memset(&test, 0, sizeof(test));

    // Create a uORB topic advertisement
    orb_advert_t test_pub = orb_advertise(ORB_ID(test), &test);

    for (int i=0; i<40; i++)
        {
        test.timestamp = hrt_absolute_time();
        test.test_value = 69;

        orb_publish(ORB_ID(test), test_pub, &test);

        //sleep for 0.2s
        usleep (200000);
        }

    PX4_INFO("inject_test finished!");

    return 0;
}
