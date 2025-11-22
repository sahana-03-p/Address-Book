# Address-Book
Implemented a Basic Address Book in C to manage contacts with Name, Mobile Number, and Email. Features include add, search, edit, delete, and save & exit, allowing users to efficiently manage and store contact information permanently.

⚙ Key Features:
 • Add Contact – Save a new contact with Name, Mobile Number & Email Address
 • Search Contact – Find contacts by Name, Mobile or Email
 • Edit Contact – Update existing contact details
 • Delete Contact – Remove unwanted entries
 • View Contacts – Display all saved contacts in one list
 • Persistent Storage – Changes are saved to and loaded from a file
 • Safe Exit – Close the application with data integrity maintained
📁 File-Based Persistence
 The system loads and writes contact data seamlessly from file storage, ensuring all modifications persist across sessions.
📜 Validation & Robustness
 • Validates 10-digit mobile numbers
 • Validates email address format
 • Provides clear prompts and handles user errors gracefully
🧠 Skills Gained:
 • C programming: structures, Function pointers, arrays
 • File I/O: fopen/fclose, fscanf/fprintf for data persistence
 • Real-world logic: implementing add/search/edit/delete operations reliably
 • Input validation and robust error handling
💬 Challenges Faced & Overcome:
 • Ensuring reliable file save/update operations without corrupting data ✅
 • Handling index shifts correctly during contact edit and delete operations ✅
