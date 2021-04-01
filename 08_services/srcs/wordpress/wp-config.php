<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-svc:3306' );
#define( 'WP_HOME', 'http://192.168.99.151:5050/' ); # EXTERNAL IP
define( 'WP_HOME', 'http://wordpress-svc:5050/' ) ;
define( 'WP_SITEURL', 'http://192.168.99.151:5050/' ); # EXTERNAL IP

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('FS_METHOD', 'direct');
/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         '@-|1+0?O^>6eI|7o$_F;&@lOs)4XRVMw7XDZ+4EI3UY)C-m{}49Z,3o|zqo[L1:9');
define('SECURE_AUTH_KEY',  'Zx17A|)75|7|]f+W>.,!+yA2Y<g*:|Cz+y!EQTMW%=NMa>VJje51wv*MX&;>@5Ez');
define('LOGGED_IN_KEY',    '7b!d`rH$Ys2Iut91ImfB.Rerl-+)pyBA7MOZpIm+^[p,-|_fo[^X/0oe @zVGcio');
define('NONCE_KEY',        '<*$6o?:_t.xa,9RE3*oy<cG>=}s!a-B3~(g=?*{!f}W}yS^ntJP^wY|%d)iK;gw+');
define('AUTH_SALT',        '$_uh|h8[PHT-$N`+qAvY;vpw~H~EH+P_$-*7ayY}+MZ_#2nk{8su3woR[@ma5!U,');
define('SECURE_AUTH_SALT', 'g.a.eI1N/n$L7D#KF+~E`M+NXkj)V=@xL@=~k|.bV/0!#S/X!i1FidyPY(5ZS!ld');
define('LOGGED_IN_SALT',   'RU6jtD8Y>1.[Z3Byhp+8a{y A+(%hNYa+{BZ/oih,iWS6&z62|M{*$K!t-c@od_P');
define('NONCE_SALT',       '+^%1A2!.!Jzk(#IorW&-M>YQh6o88<74R#/@F+AE$|,bF2O[NezUdq[%dPWmM=/G');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
