pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pw-pal.pc
EXTRA_DIST = $(pkgconfig_DATA)

AM_CFLAGS = -Wno-unused-parameter -Wno-unused-result -I/usr/include/pipewire-0.3 -I/usr/include/spa-0.2

lib_LTLIBRARIES      = libpipewire-module-pal.la
libpipewire_module_pal_la_SOURCES   = pw-pal-plugin.c
libpipewire_module_pal_la_CFLAGS = $(AM_CFLAGS) $(PALHEADERS_CFLAGS)
libpipewire_module_pal_la_LDFLAGS   = -shared -avoid-version
libpipewire_module_pal_la_LIBADD   = -ltinyalsa -ldl -lexpat -lpal -lagm

install-data-hook:
	mkdir -p $(DESTDIR)/usr/share/pipewire/pipewire.conf.d/
	mkdir -p $(DESTDIR)/usr/share/wireplumber/wireplumber.conf.d/
	$(INSTALL_DATA) $(srcdir)/pw-pal-plugin.conf $(DESTDIR)/usr/share/pipewire/pipewire.conf.d/
	$(INSTALL_DATA) $(srcdir)/60-disable-alsa.conf $(DESTDIR)/usr/share/wireplumber/wireplumber.conf.d/
