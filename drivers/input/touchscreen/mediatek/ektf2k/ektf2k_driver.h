#ifndef _LINUX_ELAN_KTF2K_H
#define _LINUX_ELAN_KTF2K_H

#include <linux/hrtimer.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
//#include <linux/io.h>

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/bitops.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/byteorder/generic.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <linux/interrupt.h>
#include <linux/time.h>

#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <mt_boot_common.h>

#include <linux/jiffies.h>
#include <linux/miscdevice.h>

#define ELAN_KTF2K_NAME "elan-ktf2k"

#define PWR_STATE_DEEP_SLEEP              0
#define PWR_STATE_NORMAL                  1
#define PWR_STATE_MASK                    BIT(3)

#define CMD_S_PKT                         0x52
#define CMD_R_PKT                         0x53
#define CMD_W_PKT                         0x54

#define HELLO_PKT                         	0x55
#define TWO_FINGERS_PKT             	   	0x5A
#define FIVE_FINGERS_PKT                  	0x5D
#define MTK_FINGERS_PKT                   	0x6D    /** 2 Fingers: 5A, 5 Fingers: 5D, 10 Fingers: 62 **/
#define TEN_FINGERS_PKT              		0x62

#define RESET_PKT                    			0x77
#define CALIB_PKT                    			0xA8

#define TPD_OK 0


struct elan_ktf2k_i2c_platform_data {
         uint16_t version;
         int abs_x_min;
         int abs_x_max;
         int abs_y_min;
         int abs_y_max;
         int intr_gpio;
         int (*power)(int on);
};

struct osd_offset{
        int left_x;
        int right_x;
        unsigned int key_event;
};





#endif /* _LINUX_ELAN_KTF2K_H */
