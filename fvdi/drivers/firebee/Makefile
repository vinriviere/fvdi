#!make -f
#
# This software is licensed under the GNU General Public License.
# Please, see LICENSE.TXT for further information.
#

#
# gcc >= 2.95.3 (sparemint) version
#

TARGET = firebee.sys

all: $(TARGET)

top_srcdir = ../..

#CPU     = v4e
OPTS    = -mshort -O2 -fomit-frame-pointer
include $(top_srcdir)/CONFIGVARS
CC=m68k-atari-mint-gcc

CFLAGS  = $(CPUOPTS) $(OPTS) $(WARNINGS) -I$(top_srcdir)/include -I$(top_srcdir)/drivers/include

LDEFS=\
	--defsym _VRAM=0x60000000 \
	--defsym __MBAR=0xFF000000 \
	--defsym FPGA_CS2_BASE=0xf0000000 \
	--defsym _videl_regs=0xffff8200 \
	--defsym _fb_vd_clut=0xf0000000 \
	--defsym _fb_vd_cntrl=0xf0000400 \
	--defsym _fb_vd_border=0xf0000404 \
	--defsym _fb_vd_pll_config=0xf0000600 \
	--defsym _fb_vd_frq=0xf0000604 \
	--defsym _fb_vd_pll_reconfig=0xf0000800 \
	--defsym _blitter_registers=0xffff8a00 \
	--defsym _falcon_busctl=0xffff8007

M68K_ATARI_MINT_LDFLAGS += $(LDEFS) -Wl,-Map,mapfile

SINCSRC = \
	$(top_srcdir)/drivers/bitplane/1_expand.inc

SSRC = \
	../common/c_common.s \
	../common/common.s \
	../common/clip.s

CSRC = \
	init.c \
	colours.c \
	printf.c \
	fb_spec.c \
	firebee.c \
	firebee_mouse.c \
	../common/modeline.c \
	16_bit.c

# handle DevPac -> gas conversions
# defines SSRC_GNU and SINCSRC_GNU variables
include $(top_srcdir)/utility/conv2gas/RULES

SINCSRC_GNU += \
	$(top_srcdir)/include/types.inc \
	$(top_srcdir)/include/macros.gnu \
	$(top_srcdir)/include/vdi.gnu \
	$(top_srcdir)/drivers/include/pixelmac.gnu

# engine binary objects
ifeq ($(CPU),v4e)
OBJECTS = $(SSRC_GNU_CF:.s=.o)
else
OBJECTS = $(SSRC_GNU:.s=.o)
endif
OBJECTS += $(CSRC:.c=.o)

$(OBJECTS): $(SINCSRC_GNU)

LIBDIR:=$(dir $(shell $(CC) $(CPUOPTS) --print-file-name=libc.a))
$(TARGET): $(OBJECTS) $(LIBFILES)
	$(AM_V_LD)$(LD) $(LDEFS) -Map mapfile -o $@ $(OBJECTS) $(LDFLAGS) -L$(LIBDIR) $(LIBS)

include $(top_srcdir)/DEPENDENCIES

strip:
	$(STRIP) --strip-all $(TARGET)

clean:: clean_gnu
	$(RM) *.o $(TARGET) *.inf *.ino
	$(RM) ../common/*.gnu.s ../common/*.cf_gnu.s ../common/*.cf_gnu.se ../common/*.o
	$(RM) mapfile

install::
	mkdir -p $(DESTDIR)/gemsys
	cp -a $(TARGET) $(DESTDIR)/gemsys/$(TARGET)
	cp -a fvdi.sys "$(DESTDIR)/fvdifb.sys"
