PKGNAME=toybox
PKGVER=0.8.3

build() {
	CROSS_COMPILE=x86_64-onyx- $MAKE
}

package() {
	mkdir -p $PKGDIR/usr
	mkdir -p $PKGDIR/usr/bin
	$MAKE install_flat PREFIX=$PKGDIR/usr/bin
}
