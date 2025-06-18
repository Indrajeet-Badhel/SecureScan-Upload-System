<?php
$uploadDir = "uploads/";
$uploadFile = $uploadDir . basename($_FILES["uploadedFile"]["name"]);
$email = $_POST["email"];

if (move_uploaded_file($_FILES["uploadedFile"]["tmp_name"], $uploadFile)) {
    $reportFile = "scan_report.txt";

    // Run ClamAV scanner (C binary or clamscan fallback)
    $output = shell_exec("clamscan " . escapeshellarg($uploadFile) . " > " . $reportFile);

    // Send email with Python
    $cmd = "python3 pytools/send_email.py " . escapeshellarg($email) . " " . $reportFile;
    $result = shell_exec($cmd);

    echo "<div style='padding:20px;'>File uploaded and scanned.<br>Email sent to: " . htmlspecialchars($email) . "</div>";
} else {
    echo "<div style='color:red;'>File upload failed.</div>";
}
?>
