# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mozc
PORTVERSION=	1.11.1502.102
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Mozc Japanese Input Method, Server

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/third_party/gyp/LICENSE

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
EXTRACT_DEPENDS=${PYTHON_CMD}:${PYTHON_PORTSDIR}
LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf \
		libzinnia.so:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		pkgconfig iconv gmake tar:bzip2
USE_PYTHON_BUILD=yes
USE_OPENSSL=	yes

BUILD_MOZC_LIST?=	mozc_server

.if   ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-server

LICENSE=		BSD NAISTL
LICENSE_COMB=		multi
LICENSE_FILE_BSD=	${WRKSRC}/third_party/gyp/LICENSE
LICENSE_DISTFILES_BSD=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_NAME_NAISTL=	Nara Institute of Science and Technology License
LICENSE_PERMS_NAISTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_NAISTL=	${WRKSRC}/data/dictionary_oss/README.txt
LICENSE_DISTFILES_NAISTL=${DISTNAME}${EXTRACT_SUFX}
.elif ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
USE_GNOME=	glib20 gtk20
USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build
.elif ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
USE_XORG=	xcb
USE_GNOME=	glib20 gtk20
.elif ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
USE_EMACS=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=		Does not compile on FreeBSD 7.X
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: segfault
.endif

GYP_DEFINES=	use_libprotobuf=1 \
		channel_dev=0 \
		enable_unittest=0 \
		zinnia_model_file="${LOCALBASE}/share/tegaki/models/zinnia/handwriting-ja.model"
BUILD_MODE=	Release
BUILD_CMD=	${SETENV} ${MAKE_ENV} PATH=/bin:/usr/bin:${PATH} ${MAKE_CMD}
BUILD_MOZC_CMD=	cd ${BUILD_WRKSRC} && \
		${SETENV} BUILD_COMMAND="${WRKSRC}/mozcmake" \
		PYTHONPATH=${WRKSRC}/third_party/gyp/local/lib/python${PYTHON_VER}/site-packages \
		${DEBUG} \
		GYP_DEFINES="${GYP_DEFINES}" \
		CC_host="${CC}" \
		CXX_host="${CXX}" \
		LD_host="${CXX}" \
		AR_host="${AR}" \
		${PYTHON_CMD} build_mozc.py
BUILD_MOZC_CMD_BUILD=	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} ${_MAKE_JOBS}
BUILD_GYP_CMD=	cd ${WRKSRC}/third_party/gyp && \
			${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP}

post-patch:
	${MKDIR} ${WRKSRC}/mozc_build_tools/linux
	${LN} -sf ${LOCALBASE}/bin/protoc ${WRKSRC}/mozc_build_tools/linux/
	${REINPLACE_CMD} 's,-liconv,${ICONV_LIB},g' ${WRKSRC}/gui/qt_libraries.gypi
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
	${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
		${WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh
	${REINPLACE_CMD} "s,/usr,${LOCALBASE:Q}," \
		${WRKSRC}/unix/fcitx/mozc.conf
.endif

.if ! ${BUILD_MOZC_LIST:Mmozc_el}
${WRKSRC}/mozcmake:
	${PRINTF} "%s\n%s\n" "#!/bin/sh" 'exec ${BUILD_CMD} $$@' \
		> ${WRKSRC}/mozcmake
	${CHMOD} +x ${WRKSRC}/mozcmake

post-configure: ${WRKSRC}/mozcmake
	${BUILD_GYP_CMD} ${PYDISTUTILS_CONFIGURE_TARGET} \
		${PYDISTUTILS_CONFIGUREARGS}
	${BUILD_GYP_CMD} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS}
	${BUILD_GYP_CMD} ${PYDISTUTILS_INSTALL_TARGET} \
		--prefix=${WRKSRC}/third_party/gyp/local
	${BUILD_MOZC_CMD} gyp \
		--gypdir=${WRKSRC}/third_party/gyp/local/bin \
		--server_dir="${PREFIX}/bin" \
		--localbase="${LOCALBASE}" \
		--ldflags="${LDFLAGS} -fstack-protector -L${LOCALBASE}/lib" \
		--include_dirs="${LOCALBASE}/include" \
		--openssl_cflags="${OPENSSL_CFLAGS}" \
		--openssl_ldflags="${OPENSSL_LDFLAGS}" \
		--openssl_inc="-I${OPENSSLINC}" \
		--openssl_lib="-lssl -lcrypto -L${OPENSSLLIB}" \
		${GYP_OPTIONS}

pre-build:
	${BUILD_MOZC_CMD} build_tools -c ${BUILD_MODE} ${_MAKE_JOBS}
.endif

# mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server" || defined(makesum)
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

MASTER_SITES+=	LOCAL/kuriyama:zipcode
DISTFILES+= \
	ken_all-20130628.lzh:zipcode \
	jigyosyo-20130628.lzh:zipcode

EXTRACT_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

PLIST_FILES+=	bin/mozc_server \
		bin/mozc_emacs_helper

post-extract-mozc_server:
	@for F in jigyosyo-20130628.lzh ken_all-20130628.lzh; do \
		${LHA_CMD} xfq2w=${WRKSRC}/data/dictionary_oss ${DISTDIR}/$$F; \
	done
	@cd ${WRKSRC}/data/dictionary_oss && \
		${PYTHON_CMD} ${WRKSRC}/dictionary/gen_zip_code_seed.py \
		--zip_code=ken_all.csv --jigyosyo=jigyosyo.csv \
		>> dictionary09.txt

post-extract: post-extract-mozc_server

do-build-mozc_server:
	${BUILD_MOZC_CMD_BUILD} server/server.gyp:mozc_server
	${BUILD_MOZC_CMD_BUILD} unix/emacs/emacs.gyp:mozc_emacs_helper

do-install-mozc_server:
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_server \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_emacs_helper \
		${STAGEDIR}${PREFIX}/bin
.endif

# mozc_tool
.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=1

RUN_DEPENDS+=	${LOCALBASE}/share/tegaki/models/zinnia/handwriting-ja.model:${PORTSDIR}/japanese/tegaki-zinnia-japanese

PLIST_FILES+=	libexec/mozc_tool \
		bin/mozc_tool \
		%%DATADIR%%/icons/product_logo.png \
		%%DATADIR%%/icons/update_uptodate.png
PLIST_DIRS+=	%%DATADIR%%/icons ${DATADIR_REL}
SUB_FILES+=	mozc_tool

do-build-mozc_tool:
	${BUILD_MOZC_CMD_BUILD} gui/gui.gyp:mozc_tool

do-install-mozc_tool:
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_tool \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/mozc_tool ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${STAGEDIR}${DATADIR}/icons/product_logo.png
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${STAGEDIR}${DATADIR}/icons/update_uptodate.png
.endif

# ibus_mozc
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=1 \
		enable_gtk_renderer=1

LIB_DEPENDS+=	libibus-1.0.so:${PORTSDIR}/textproc/ibus
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify

PLIST_FILES+=	bin/mozc_renderer \
		libexec/ibus-engine-mozc \
		%%DATADIR%%/icons/alpha_full.png \
		%%DATADIR%%/icons/alpha_half.png \
		%%DATADIR%%/icons/dictionary.png \
		%%DATADIR%%/icons/direct.png \
		%%DATADIR%%/icons/hiragana.png \
		%%DATADIR%%/icons/katakana_full.png \
		%%DATADIR%%/icons/katakana_half.png \
		%%DATADIR%%/icons/product_icon.png \
		%%DATADIR%%/icons/properties.png \
		%%DATADIR%%/icons/tool.png \
		share/ibus/component/mozc.xml
PLIST_DIRS+=	%%DATADIR%%/icons ${DATADIR_REL}

do-build-ibus_mozc:
	${BUILD_MOZC_CMD_BUILD} \
		unix/ibus/ibus.gyp:ibus_mozc \
		renderer/renderer.gyp:mozc_renderer

do-install-ibus_mozc:
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_renderer \
		${STAGEDIR}${PREFIX}/bin/mozc_renderer
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/ibus_mozc \
		${STAGEDIR}${PREFIX}/libexec/ibus-engine-mozc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ibus/component
	${INSTALL_DATA} \
		${WRKSRC}/out_linux/${BUILD_MODE}/obj/gen/unix/ibus/mozc.xml \
		${STAGEDIR}${PREFIX}/share/ibus/component/mozc.xml
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/${F}.png \
		${STAGEDIR}${DATADIR}/icons/${F:S/^ui-//}.png
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${STAGEDIR}${DATADIR}/icons/product_icon.png
.endif

# fcitx_mozc
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc" # || make(makesum)
PATCH_SITES=	http://fcitx.googlecode.com/files/
PATCHFILES=	fcitx-${DISTNAME}.2.patch
.endif
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
PATCH_DIST_STRIP=-p2

GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

LIB_DEPENDS+=	fcitx-core:${PORTSDIR}/chinese/fcitx
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions

PLIST_FILES+=	lib/fcitx/fcitx-mozc.so \
		share/fcitx/addon/fcitx-mozc.conf \
		share/fcitx/inputmethod/mozc.conf \
		%%DATADIR%%/icon/mozc.png \
		%%DATADIR%%/icon/mozc-alpha_full.png \
		%%DATADIR%%/icon/mozc-alpha_half.png \
		%%DATADIR%%/icon/mozc-direct.png \
		%%DATADIR%%/icon/mozc-hiragana.png \
		%%DATADIR%%/icon/mozc-katakana_full.png \
		%%DATADIR%%/icon/mozc-katakana_half.png \
		%%DATADIR%%/icon/mozc-dictionary.png \
		%%DATADIR%%/icon/mozc-properties.png \
		%%DATADIR%%/icon/mozc-tool.png \
		share/locale/ja/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_CN/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_TW/LC_MESSAGES/fcitx-mozc.mo
PLIST_DIRS+=	%%DATADIR%%/icon ${DATADIR_REL}

do-build-fcitx_mozc:
	${BUILD_MOZC_CMD_BUILD} unix/fcitx/fcitx.gyp:fcitx-mozc

do-install-fcitx_mozc:
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/fcitx \
		${STAGEDIR}${PREFIX}/share/fcitx/addon \
		${STAGEDIR}${PREFIX}/share/fcitx/inputmethod
	${INSTALL_LIB} \
		${WRKSRC}/out_linux/${BUILD_MODE}/fcitx-mozc.so \
		${STAGEDIR}${PREFIX}/lib/fcitx/fcitx-mozc.so
	${INSTALL_DATA} \
		${WRKSRC}/unix/fcitx/fcitx-mozc.conf \
		${STAGEDIR}${PREFIX}/share/fcitx/addon/fcitx-mozc.conf
	${INSTALL_DATA} \
		${WRKSRC}/unix/fcitx/mozc.conf \
		${STAGEDIR}${PREFIX}/share/fcitx/inputmethod/mozc.conf
	@${MKDIR} ${DATADIR}/icon
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/${F}.png \
		${STAGEDIR}${DATADIR}/icon/${F:S,^ui-,mozc-,}.png
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/data/images/product_icon_32bpp-128.png \
		${STAGEDIR}${DATADIR}/icon/mozc.png
.for L in ja zh_CN zh_TW
	${INSTALL_DATA} \
		${WRKSRC}/out_linux/${BUILD_MODE}/obj/gen/unix/fcitx/po/${L}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${L}/LC_MESSAGES/fcitx-mozc.mo
.endfor
.endif

# mozc_el
.if ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
CATEGORIES+=	elisp
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions

PLIST_FILES+=	${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.el \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.elc \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/leim-list.el
PLIST_DIRS+=	${EMACS_VERSION_SITE_LISPDIR}/mozc

do-build-mozc_el:
	cd ${WRKSRC}/unix/emacs && \
		${EMACS_CMD} -batch -q -no-site-file -no-init-file \
				-f batch-byte-compile mozc.el

do-install-mozc_el:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc
	${INSTALL_DATA} \
		${WRKSRC}/unix/emacs/mozc.el \
		${WRKSRC}/unix/emacs/mozc.elc \
		${FILESDIR}/leim-list.el \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/
.endif

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

.include <bsd.port.post.mk>
