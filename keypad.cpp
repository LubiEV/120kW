/******************************************************************************
* Copyright (C), 2016-2017, Sunny.Guo
* FileName: keypad.c 
* Author: Sunny.Guo
* Version: 1.0
* Date: 2017年 01月 19日 星期四 10:12:50 CST
* Description: keypad operation functions
*
* History:        
*  <author>  	<time>   	<version >   	<desc>
*  Sunny.Guo   	19/01/2017      1.0     	create this moudle  
*                                                                          
* Licensed under GPLv2 or later, see file LICENSE in this source tree.
*******************************************************************************/
#include "common.h"
#include "keypad.h"
#include "poll.h"
    struct input_event ev[64];
/******************************************************************************
  Function:       keypad_init
  Description:    initialize keypad device
  Input:          keypad    	--  keypad device name, such as '/dev/input/event0'
                   
  Output:          
  Return:         int		-- return the keypad fd
  Others:         NONE
*******************************************************************************/
int	keypad_init(const char * keypad,int pfd)
{          
    char name[256] = "IC Reader IC Reader";
    pfd = open(keypad, O_RDONLY); //O_NONBLOCK
    if (pfd < 0) {
        dbg_perror("Open keys event node failed\n");
    }
     ioctl (pfd, EVIOCGNAME (sizeof (name)), name);
     printf ("Reading From : %s (%s)\n", keypad, name);
    return pfd;
}
int keypad_monitor(int fd)
{
	int ret = 0;
    fd_set key_ev_fds;

	FD_ZERO(&key_ev_fds);
	FD_SET(fd, &key_ev_fds);
	
	ret = select(sizeof(key_ev_fds)+1, &key_ev_fds, NULL, NULL, NULL);
	if ( ret < 0){
		dbg_perror("select key event failed");
		}
	
	if(FD_ISSET(fd, &key_ev_fds)){
		
		ret = read(fd, ev, sizeof(struct input_event));
		if ( ret < 0){
			dbg_perror("Read key event failed");
			}
		}
	return ret;
}
