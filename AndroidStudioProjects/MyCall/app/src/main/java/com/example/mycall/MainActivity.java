package com.example.mycall;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText numberInput;
    private EditText smsTextInput;
    private Button callButton;
    private Button smsButton;
    private static final int PERMISSION_CALL = 1;
    private static final int PERMISSION_SMS = 2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        numberInput = findViewById(R.id.phoneNumberInput);
        smsTextInput = findViewById(R.id.smsMessageInput);
        callButton = findViewById(R.id.button);
        smsButton = findViewById(R.id.smsButton);

        callButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startPhoneCall();
            }
        });

        smsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendSMSMessage();
            }
        });
    }

    private void startPhoneCall() {
        String phoneNumber = numberInput.getText().toString();
        if (phoneNumber.trim().length() > 0) {
            if (ContextCompat.checkSelfPermission(MainActivity.this,
                    Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {

                ActivityCompat.requestPermissions(MainActivity.this,
                        new String[] {Manifest.permission.CALL_PHONE}, PERMISSION_CALL);
            }
            else {

                String dial = "tel:" + phoneNumber;
                startActivity(new Intent(Intent.ACTION_CALL, Uri.parse(dial)));
            }
        }
    }

    private void sendSMSMessage() {
        String phoneNumber = numberInput.getText().toString();
        if (phoneNumber.trim().length() > 0) {
            if (ContextCompat.checkSelfPermission(MainActivity.this,
                    Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {

                ActivityCompat.requestPermissions(MainActivity.this,
                        new String[] {Manifest.permission.SEND_SMS}, PERMISSION_SMS);
            }
            else {
                String smsBody = smsTextInput.getText().toString();
                Intent I = new Intent(Intent.ACTION_VIEW, Uri.fromParts("sms", phoneNumber, null));

                I.putExtra("sms_body", smsBody);

                try
                {
                    startActivity(I);
                    finish();
                    Log.i("Sms Send","");
                }
                catch(Exception e)
                {
                    Toast.makeText(MainActivity.this,"Sms not send", Toast.LENGTH_LONG).show();
                }
            }
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (requestCode == PERMISSION_CALL) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                startPhoneCall();
            }
        }

        if (requestCode == PERMISSION_SMS) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                sendSMSMessage();
            }
        }
    }
}
