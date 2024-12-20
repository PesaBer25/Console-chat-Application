
---

# C Console Chat Application

## Overview

This project is a secure chat application implemented in C for the console. It supports multiple clients connecting to a single server and facilitates encrypted communication using the **Diffie-Hellman key exchange algorithm** for secure key sharing and **XOR-based encryption** for message confidentiality.

The application uses **multiplexing** with the `select()` function to handle multiple clients simultaneously and ensure non-blocking operations for sending and receiving messages. Users can join chat rooms or have private chats with other online users.

---

## Features

### Server
1. **Multiplexing with `select()`**
   - Handles multiple client connections simultaneously without blocking.
   - Efficiently monitors file descriptors for incoming data or connection requests.

2. **Broadcast Messaging**
   - Relays messages from one client to all connected clients within a chat room.
   - Ensures encrypted messages are only decrypted by recipients.

3. **Private Messaging**
   - Allows users to send encrypted private messages to other online users.
   - Prevents message broadcast to other clients in the system.

4. **Diffie-Hellman Key Exchange**
   - Securely establishes shared encryption keys with each client during connection.

5. **Chat Rooms**
   - Users can join predefined chat room to communicate with multiple clients in the same room.
   - Messages within the room are broadcasted to all connected clients in that room.

---

### Client
1. **Non-blocking Send and Receive**
   - Uses multiplexing to send and receive messages asynchronously.

2. **Message Encryption**
   - Messages are encrypted using XOR encryption with a key derived via Diffie-Hellman.

3. **Join Chat Rooms**
   - Users can chat in one common chat room with all connected members.

4. **Private Chat**
   - Users can initiate private chats with other online users by specifying their username.

5. **User-Friendly Interface**
   - Text-based console interface for sending and receiving messages.

6. **connected Users**
   - Users can view a list of all active members.

---

## Architecture

### Diffie-Hellman Key Exchange
- The server and clients generate public-private key pairs.
- Exchange public keys over an unsecured channel.
- Derive a shared secret key used for XOR encryption.

### XOR Encryption
- The derived shared key is used to encrypt/decrypt messages.
- XOR encryption provides lightweight, fast encryption suitable for this context.

### Multiplexing with `select()`
- The `select()` function is used to monitor multiple sockets:
  - For the server: monitors the listening socket and connected client sockets.
  - For the client: monitors the input stream and socket connection.

### Chat Room & Private Messaging
- The server supports a chat room where users can communicate with all other members in that same room.
- Private messaging allows a client to send messages to specific users, bypassing the chat room broadcast.

---

## Requirements

- **Compiler**: GCC (via MinGW or similar) or Visual Studio.
- **Operating System**: Windows 7 or later.
- **Libraries**:
  - `winsock2.h` for sockets.
  - `ws2_32.lib` for networking.

---

## Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/PesaBer25/Console-chat-App.git
   cd Console-chat-App
   ```

2. **Compile the Code**
   - Use MinGW with GCC:
     ```bash
     gcc -o server.exe server.c -lws2_32
     gcc -o client.exe client.c -lws2_32
     ```
   - For Visual Studio:
     - Open the project in Visual Studio.
     - Add `ws2_32.lib` as a dependency in the linker settings.
     - Compile the `server.c` and `client.c` files.

3. **Run the Application**
   - Start the server:
     ```bash
     ./server
     ```
   - Start the client(s):
     ```bash
     ./client
     ```

---

## Usage

1. **Start the Server**
   Launch the server on a specific port. By default, it listens on `localhost:2000`.

2. **Connect Clients**
   Run the client program.

3. **Join a Chat Room**
   - Clients join one major chat room on being connected and create their username to start communicating with members.
   - Messages will be broadcasted to everyone in the room.

4. **View active members**
   - clients can view members by typing a forward slash followed by the word contacts. Example: `/contacts`.

5. **Private Messaging**
   - Clients can send private messages to specific users using a forward slash followed by their username. Example: `/John Hello John!`.
   - The message will be sent only to the recipient and not to the chat room.

6. **Exit**
   Press `Ctrl+C` to terminate the server or `Q` to terminate the client.

---

## Security Features

1. **Diffie-Hellman Key Exchange**
   - Ensures secure key sharing even over unsecured channels.

2. **XOR Encryption**
   - Lightweight encryption to protect message content.

3. **No Plaintext Transmission**
   - All messages sent over the network are encrypted.

4. **Private Chat Security**
   - Private messages are only visible to the intended recipient.

---

## Limitations
1. XOR encryption is lightweight but not as secure as modern algorithms like AES. Use with caution for sensitive applications.
2. Currently supports text-based messages only (no file transfer or multimedia).
3. No authentication mechanism implemented.

---

## License

This project is licensed under the MIT License.  
Click [here](https://opensource.org/licenses/MIT) to view the full license.

![MIT License Badge](https://img.shields.io/badge/License-MIT-blue.svg)

---

## Contact

For any inquiries, feedback, or support, feel free to reach out:

📧 **Email**: [rayonspy@gmail.com](mailto:rayonspy@gmail.com)  
💻 **GitHub**: [PesaBer25](https://github.com/PesaBer25)  

---
