# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	sudo
DISTVERSION=	1.8.10p3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SUDO}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Allow others to run commands as root

LICENSE=	sudo
LICENSE_NAME=	Sudo license
LICENSE_FILE=	${WRKSRC}/doc/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
LDFLAGS+=	-lgcc
LDFLAGS+=	-lssp_nonshared

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--with-logincap \
		--with-long-otp-prompt

OPTIONS_DEFINE=	LDAP INSULTS DISABLE_ROOT_SUDO DISABLE_AUTH NOARGS_SHELL \
		AUDIT OPIE NLS SSSD DOCS
OPTIONS_DEFAULT=	AUDIT
OPTIONS_SUB=	yes

INSULTS_DESC=	Enable insults on failures
DISABLE_ROOT_SUDO_DESC=	Do not allow root to run sudo
DISABLE_AUTH_DESC=	Do not require authentication by default
NOARGS_SHELL_DESC=	Run a shell if no arguments are given
AUDIT_DESC=	Enable BSM audit support
OPIE_DESC=	Enable one-time passwords (no PAM support)
SSSD_DESC=	Enable SSSD backend support.

LOGFAC?=	authpriv
CONFIGURE_ARGS+=	--with-logfac=${LOGFAC}

# This is intentionally not an option.
# SUDO_SECURE_PATH is a PATH string that will override the user's PATH.
# ex: make SUDO_SECURE_PATH="/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"
.if defined(SUDO_SECURE_PATH)
CONFIGURE_ARGS+=	--with-secure-path="${SUDO_SECURE_PATH}"
.endif

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=	-L${LOCALBASE}/lib -lintl
NLS_CFLAGS=	-I${LOCALBASE}/include

INSULTS_CONFIGURE_ON=	--with-insults
INSULTS_CONFIGURE_ON+=	--with-all-insults

LDAP_USE=	OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=${PREFIX}
SUDO_LDAP_CONF?=	ldap.conf
LDAP_CONFIGURE_ON+=	--with-ldap-conf-file=${PREFIX}/etc/${SUDO_LDAP_CONF}

DISABLE_ROOT_SUDO_CONFIGURE_ON=	--disable-root-sudo
DISABLE_AUTH_CONFIGURE_ON=	--disable-authentication
NOARGS_SHELL_CONFIGURE_ENABLE=	noargs-shell
AUDIT_CONFIGURE_WITH=	bsm-audit
OPIE_CONFIGURE_ON=	--with-opie
OPIE_CONFIGURE_OFF=	--with-pam
SSSD_CONFIGURE_ON=	--with-sssd
SSSD_RUN_DEPENDS=	sssd:${PORTSDIR}/security/sssd

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
CONFIGURE_ARGS+=	--disable-pie
.endif

post-patch:
	@${REINPLACE_CMD} -E '/install-(binaries|noexec):/,/^$$/ \
		s/\$$\(INSTALL\)/& ${STRIP}/;s/-b\~/-b ~/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,$$(srcdir)/sudoers2ldif $$(DESTDIR)$$(docdir),$$(srcdir)/sudoers2ldif $$(DESTDIR)$$(bindir),' ${WRKSRC}/plugins/sudoers/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's/mkinstalldirs $$(DESTDIR)$$(docdir)/mkinstalldirs/' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/for f in $$(OTHER_DOCS); do/d;/@LDAP@for f in $$(OTHER_DOCS_LDAP); do/d' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's/$$(DESTDIR)$$(sudoersdir) $$(DESTDIR)$$(docdir)/$$(DESTDIR)$$(sudoersdir)/' ${WRKSRC}/plugins/sudoers/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/sudo.default
	${TOUCH} ${STAGEDIR}${PREFIX}/etc/sudoers.d/.keep-me
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sudoreplay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/visudo
.for f in group_file.so sudoers.so system_group.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/sudo/${f}
.endfor

.include <bsd.port.mk>
