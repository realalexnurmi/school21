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
define( 'DB_USER', 'enena' );

/** MySQL database password */
define( 'DB_PASSWORD', '1234' );

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
define('AUTH_KEY',         'JwQ;0-?k>s|+8aG| !YVey~beo|x|s-SLgF}#uhvNhm-P9P@SW*dI^nbFoBY~iq)');
define('SECURE_AUTH_KEY',  'T4qK=#tR+s5!G1m=G?{X7vSapB[z!o,ww`kmAe|L)Yv$/22P#Xq3LKMSs.2 ,H] ');
define('LOGGED_IN_KEY',    'B+Yv`H&+iIEW+.Q/4hpzzMWcT.wl#?DB8ejTJD,8[t.a*#K&xu}Ntb%2IXsho1rU');
define('NONCE_KEY',        'a|KiFKRw`mo*A|lE5taay!+C&x>18DX.#|d5Vrp-_ls(?-:@`^>Lyh_a)BXB+kGZ');
define('AUTH_SALT',        '#7R%9&[zKk-)6R4TLpKe?.=t%n?wmD fmuE(gUQUV4wy)uz51S:txBA^K?w!z|IM');
define('SECURE_AUTH_SALT', 'd;mew(3@WU~lVbKlKlnO}.>wDKnb9>p,n%xs3z=+2$yhSK6^zyoM9i`lBz1#RmQT');
define('LOGGED_IN_SALT',   'f^Ls/H8<#5ucM#t6`yLcCcHE]ra7g}?f5@UZv4&fg>m.:`%r*c(mP}D1h]`v%$@9');
define('NONCE_SALT',       '0$yQNJDGseeN?c*r=F@}ce+-#uA.5Lh~2)~Lz,Z_W!V83czGDnU/[g[6VgS[PGp-');

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
