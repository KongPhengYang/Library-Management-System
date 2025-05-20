# Library Management System

## Overview

This is a basic Library Management System developed as a group project for **Advanced Object-Oriented Design**. It helps small libraries manage books, users, and admins via a simple terminal-based interface. The system includes user registration, book borrowing/returning, admin-level control, and persistent data storage.

## Team Members

- **Kong Pheng Yang**
- **Jamison Taft**
- **Sam Dorvinen**
- **Dr. Murshed** (Instructor)

## Features

### Admin Capabilities
- Admin login and authentication
- Add, remove, and edit books
- Add, remove, and edit user accounts
- View library statistics (number of users/books)
- Borrow and return books (on behalf of users)
- Search for books and users

### User Capabilities
- Register a new account
- Login with ID and password
- Borrow up to 4 books at once
- Return borrowed books
- View personal borrowing history
- View login information
- Search for books by title or author

## Technical Highlights

- **Abstract Base Class**: `Person` (with `User` and `Admin` inheriting)
- **Singleton Pattern**: `Library` ensures only one instance handles data
- **Vectors**: Used for dynamically storing books, users, and admins
- **Polymorphism**: `printSummary()` implemented differently for `Admin` and `User`
- **File I/O**: Persistent storage via `saveAll()` to `library_data.txt`
- **Search**: Keyword-based searching through title, author, or user info

## Conclusion

This project fulfilled all key OOP goals including:
- Use of abstract classes, inheritance, polymorphism
- Static members and singleton pattern
- Encapsulation and file management
- A fully functional and user-friendly CLI program
