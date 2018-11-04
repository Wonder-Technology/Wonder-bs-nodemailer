[@bs.deriving abstract]
type sendOptions = {
  from: string,
  [@bs.as "to"]
  to_: string,
  [@bs.optional]
  subject: string,
  [@bs.optional]
  text: string,
};

type transporter = {
  sendMail: (sendOptions, (string, string) => unit) => unit,
};

type auth = {
  .
  "user": string,
  "pass": string,
};

[@bs.deriving abstract]
type config = {
  host: string,
  port: int,
  auth,
};

[@bs.module "nodemailer"]
external createTransportWithConfig : config => transporter = "createTransport";

let createTransport = (~host, ~port, ~auth, _) =>
  config(~host, ~port, ~auth) |> createTransportWithConfig;