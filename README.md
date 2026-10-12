# AbyssLock

AbyssLock – lock screen for Abyssland, fork of [hyprlock](https://github.com/hyprwm/hyprlock) (BSD-3, © hyprwm/vaxerski).

A simple, multi-threaded and GPU-accelerated screen locking utility using the ext-session-lock protocol.

## Features
 - Uses the ext-session-lock protocol
 - Support for fractional-scale
 - Fully GPU accelerated
 - Multi-threaded resource acquisition
 - Blurred screenshot as the background
 - Native fingerprint support (using libfprint's dbus interface)
 - Some of Abyssland's eyecandy: gradient borders, blur, animations, shadows, etc.

## Configuration
The config file is `~/.config/abyss/abysslock.conf` (an example is installed to `/opt/abyss/share/abyss/abysslock.conf`). The binary is `abysslock`.
Unlocking via `SIGUSR1` works like in hyprlock.

## Building and installing (Abyssland ecosystem)

Dependencies: cairo, Abyssgraphics, Abyssparse, Abyssutils, Abyss-scanner, mesa (libgbm, libdrm, OpenGL), pam (`pam-devel` on Void), pango, sdbus-c++ >= 2.0.0, wayland-client, wayland-protocols, xkbcommon.

The Abyss libraries are installed to `/opt/abyss`. From the `AbysslandWC` workspace:

```sh
JOBS=2 sh tools/build.sh AbyssLock
```

PAM: `/opt/abyss` is installed without root, but PAM only reads `/etc/pam.d`. The build puts the service file at `/opt/abyss/etc/pam.d/abysslock`; copy it once as root (also done by `tools/setup-root.sh`):

```sh
sudo install -m644 /opt/abyss/etc/pam.d/abysslock /etc/pam.d/abysslock
```

Without it abysslock falls back to the `su` PAM service.

## Credits

AbyssLock exists thanks to **[hyprlock](https://github.com/hyprwm/hyprlock)**, created by **Hypr Development** at **[hyprwm](https://github.com/hyprwm)**. All credit for the original work goes to them – please support the original project.

Abyss is an independent project and is **not affiliated with or endorsed by hyprwm**.

## License

This project is licensed under the **BSD 3-Clause License**. The original copyright notice is kept in [`LICENSE`](LICENSE) as required.

## Contributors

- [bb8TheRobot](https://github.com/bb8TheRobot)
- Claude (Anthropic) – AI pair programmer
