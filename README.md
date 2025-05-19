# M-PESA MVP Mockup

This project is a simple front-end mock-up of a Minimum Viable Product (MVP) for an M-PESA-like mobile money application. It's built using HTML, Tailwind CSS for styling, and vanilla JavaScript for basic interactivity.

## Features

The mockup currently simulates the following M-PESA features:

* **Send Money:** Allows users to enter a recipient's phone number, amount, and a mock PIN to simulate sending money.
* **Withdraw Cash:** Allows users to enter an agent number, amount, and a mock PIN to simulate withdrawing cash.
* **Buy Airtime:** Allows users to enter a phone number (for self or other), amount, and a mock PIN to simulate buying airtime.
* **Check Balance:** Displays a mock account balance.

## Technologies Used

* **HTML5:** For the basic structure of the application.
* **Tailwind CSS:** For styling and creating a responsive user interface.
    * Loaded via CDN: `<script src="https://cdn.tailwindcss.com"></script>`
* **JavaScript (Vanilla JS):** For handling user interactions, page navigation (simulated), form input validation, and mock transaction processing.
* **Google Fonts (Inter):** For typography.

## How to Run

1.  **Clone the repository (optional):**
    ```bash
    git clone [https://github.com/blacksnowmartin/mpesa-mvp-mockup.git](https://github.com/blacksnowmartin/mpesa-mvp-mockup.git)
    cd mpesa-mvp-mockup
    ```

2.  **Open the HTML file:**
    * Simply open the `mpesa_mockup.html` (or `index.html` if you renamed it) file in any modern web browser (like Chrome, Firefox, Safari, or Edge).

## Structure

* **`mpesa_mockup.html` (or `index.html`):** The single HTML file containing all the structure, styles (inline `<style>` block and Tailwind classes), and JavaScript logic.
* **Pages/Sections:**
    * `homePage`: The main menu with options.
    * `sendMoneyPage`: Form for sending money.
    * `withdrawCashPage`: Form for withdrawing cash.
    * `buyAirtimePage`: Form for buying airtime.
* **JavaScript Logic:**
    * `showPage(pageId)`: Manages displaying the active "page".
    * `showMessage(message, type)`: Displays user feedback messages.
    * `processSendMoney()`, `processWithdrawCash()`, `processBuyAirtime()`: Mock functions for handling transactions.
    * `checkBalance()`: Displays the mock balance.
    * Input validation and balance updates are handled within these functions.

## Important Notes

* **Mock Functionality:** This is a **front-end mockup only**. It does **not** connect to any real M-PESA backend services or perform actual financial transactions. The PIN is not secured, and the balance is just a client-side variable.
* **Purpose:** This MVP is intended for demonstration, learning, or as a starting point for a more complex application.
* **Styling:** Uses Tailwind CSS utility classes directly in the HTML and some custom CSS in a `<style>` block for base styles and message box.

## Future Enhancements (Possible Ideas)

* Integrate with a mock backend or a simple local storage solution for data persistence.
* Add more M-PESA services (e.g., Lipa na M-PESA, Pay Bill).
* Implement more robust form validation.
* Improve UI/UX with more animations or transitions.
* Convert to a JavaScript framework like React, Vue, or Angular for a more scalable application.

## License

This project is for demonstration purposes. 
