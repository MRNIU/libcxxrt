
/* This file is a part of MRNIU/MiniCRT (https://github.com/MRNIU/MiniCRT).
 *
 * link.ld for MRNIU/MiniCRT. */

/* OUTPUT_FORMAT(macho64) */

ENTRY(mini_crt_entry)

SECTIONS {
	.text : ALIGN(4K) {
		*(.text)
	}

	.rodata : ALIGN(4K) {
		*(.rodata)
	}

    .data : ALIGN(4K) {
		PROVIDE(ctors_start = .);
	    *(.ctor*)
	    PROVIDE(ctors_end = .);
	    PROVIDE(dtors_start = .);
	    *(.dtor*)
	    PROVIDE(dtors_end = .);
        *(.data)
    }

	.bss : ALIGN(4K) {
		*(COMMON)
		*(.bss)
	}
}
