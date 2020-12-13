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
define( 'DB_USER', 'localhost' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         'B#Z(~_ uu0r5Y$?~>GEJaY=u+y24C/8OHQjGsZ>a%s.m1nYn++;pY>*2@?R(n/R.');
define('SECURE_AUTH_KEY',  '(B,- e+(aQ/Ija(nW*UzmmDBy81LA>Dn;r]lLZ qx||!n8@ %@Yj$B_P[kdm(nk&');
define('LOGGED_IN_KEY',    '-onGz))_-1u`Ke-j0EwLOGxrwKRWBPD`ftO-4=ED=5+oxw5yPD>|rLU2+.Z~4w7K');
define('NONCE_KEY',        'g?4@e-Af_O%Us{-}p)h-+nR&^5S|f)t.*S4T ?9|m/b$X@t||rIUHQ(-+z1F0g|B');
define('AUTH_SALT',        '$/*`DY+!T`QQIy+X5)17QSiyt#CZHun-VQ$d;M<~hCBdKJQD~]=f^`vlG3l?4,@I');
define('SECURE_AUTH_SALT', '+@=az+9H}b||`yUBQ*cdGZ,>:Kj)9IHWV+B<KW`ROma4-b-wvp+s>DH<KC`G;pG4');
define('LOGGED_IN_SALT',   '(T3 `sE|L$jYlTe%L~D|G<`Y[R/Mo|adx^|eRte~f-kGU?iW+I_-<)c#xXb$~H&r');
define('NONCE_SALT',       '.+1jZ0PMG8z6:o-7|x1|SDM%3`1pPG-x5saK*9iF[;iI%2t],L:JoSOyO}FhXO-r');

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
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
