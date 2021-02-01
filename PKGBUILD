PKGNAME=toybox
PKGVER=0.8.3

build() {
	unset CC
	unset CXX
	unset LD
	export CC=gcc
	export CXX=g++
	export LD=gcc
	CROSS_COMPILE=x86_64-onyx- $MAKE
}

package() {
	mkdir -p $PKGDIR/usr
	mkdir -p $PKGDIR/usr/bin
	$MAKE install_flat PREFIX=$PKGDIR/usr/bin
}
