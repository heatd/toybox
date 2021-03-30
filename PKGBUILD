PKGNAME=toybox
PKGVER=0.8.4

build() {
	ln -sf $CC_BARE_PATH $HOST-cc
	ln -sf $(which $STRIP) $HOST-strip
	ALL_CFLAGS=$(echo "$CC" | sed 's/^[^ ]* //')
	PATH=$PWD:$PATH
	CC=cc
	STRIP=strip
	CROSS_COMPILE=$HOST- CFLAGS=$ALL_CFLAGS $MAKE
	rm $HOST-cc
	rm $HOST-strip
}

package() {
	mkdir -p $PKGDIR/usr
	mkdir -p $PKGDIR/usr/bin
	$MAKE install_flat PREFIX=$PKGDIR/usr/bin
}
