			xdef	get_video_base,set_video_base

VIDEO_BASE_HIGH		equ	$FFFF8201							
VIDEO_BASE_MIDDLE	equ	$FFFF8203

get_video_base:		movep.w	(VIDEO_BASE_HIGH),d0
			movep.w	(VIDEO_BASE_MIDDLE),d1

  			lsl.w	#8,d0				; shifts 8 bits to the left 
	   		or.w	d1,d0				; combines high and middle byte of the 24-bit video base
			rts

set_video_base:		nop
			rts
