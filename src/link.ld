
/**
 * @file link.ld
 * @brief link script
 * @author Zone.N (Zone.Niuzh@hotmail.com)
 * @version 1.0
 * @date 2023-09-07
 * @copyright MIT LICENSE
 * https://github.com/MRNIU/libcxxrt
 * @par change log:
 * <table>
 * <tr><th>Date<th>Author<th>Description
 * <tr><td>2023-09-07<td>Zone.N<td>迁移到 doxygen
 * </table>
 */

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
