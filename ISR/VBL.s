	xdef	_VBL_isr
	xref	_do_VBL_isr

_VBL_isr:
	movem.l d0-d2/a0-a2,-(sp)
	jsr _do_VBL_isr
	movem.l (sp)+,d0-d2/a0-a2
	rte 
